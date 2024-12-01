#include <chrono>
#include <memory>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <array>

#include "BlockingVectorThread.h"
#include "LockFreeQueueThread.h"

// 테스트에 사용할 데이터 구조를 템플릿으로 변경
template<size_t SIZE>
struct TestData {
  std::array<char, SIZE> data;

  TestData() {
    for(size_t i = 0; i < SIZE; ++i) {
      data[i] = static_cast<char>(i % 256);
    }
  }
};

const size_t testCount = 10000000;  //

// Timer 클래스는 그대로 유지
class Timer {
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  using Duration = std::chrono::duration<double>;

  TimePoint start_;
public:
  Timer() : start_(Clock::now()) {}

  double elapsed() const {
    return std::chrono::duration_cast<Duration>(Clock::now() - start_).count();
  }
};

// 락프리 큐 테스트 클래스도 템플릿으로 변경
template<size_t SIZE>
class LockFreeTest : public LockFreeQueueThread<TestData<SIZE>, false> {
public:
  LockFreeTest(size_t count) : LockFreeQueueThread<TestData<SIZE>, false>(1000000), count_(count), processed_(0) {}

  int push(const TestData<SIZE>& data) { return this->waiter_.push(data); }

protected:
  void run() override {
    TestData<SIZE> data;
    while (this->waiter_.pop(data) == 0) {
      processed_++;
    }
  }

private:
  const size_t count_;
  size_t processed_;
};

// 블로킹 벡터 테스트 클래스도 템플릿으로 변경
template<size_t SIZE>
class BlockingTest : public BlockingVectorThread<TestData<SIZE>> {
public:
  BlockingTest(size_t count) : BlockingVectorThread<TestData<SIZE>>(1000000), count_(count), processed_(0) {}

  bool push(const TestData<SIZE>& data) { return this->waiter_.push(data) == 0; }
  size_t processed() const { return processed_; }

protected:
  void run() override {
    std::vector<TestData<SIZE>> items;
    while (this->waiter_.pop(items) == 0) {
      for (auto &i : items)
        processed_++;
    }

    assert(processed_ == testCount);
  }

private:
  const size_t count_;
  size_t processed_;
};

template<size_t SIZE>
void runPerformanceTest(size_t testCount) {
  std::cout << "\nStarting performance test with " << testCount
      << " items, block size: " << SIZE << " bytes\n";

  // 락프리 큐 테스트
  double lockFreeTime;
  double lockFreeThroughput;
  {
    Timer timer;
    LockFreeTest<SIZE> test(testCount);
    test.start();

    size_t processed = 0;
    TestData<SIZE> data;
    for (size_t i = 0; i < testCount; ++i) {

      int res = 0;
      while ((res = test.push(data)) > 0)
        std::this_thread::yield();
      if (res < 0) break;
      ++processed;
    }

    assert(processed == testCount);

    test.stop();
    lockFreeTime = timer.elapsed();
    lockFreeThroughput = testCount / lockFreeTime;
    std::cout << "LockFree Queue completed in " << std::fixed
        << std::setprecision(3) << lockFreeTime << " seconds\n"
        << "Throughput: " << lockFreeThroughput << " ops/sec\n\n";
  }
  std::this_thread::sleep_for(std::chrono::seconds(5));

  // 블로킹 벡터 테스트
  double blockingTime;
  double blockingThroughput;
  {
    Timer timer;
    BlockingTest<SIZE> test(testCount);
    test.start();

    TestData<SIZE> data;
    for (size_t i = 0; i < testCount; ++i) {
      if (test.push(data) == false)
        assert(false);
    }

    test.stop();
    blockingTime = timer.elapsed();
    blockingThroughput = testCount / blockingTime;
    std::cout << "Blocking Vector completed in " << std::fixed
        << std::setprecision(3) << blockingTime << " seconds\n"
        << "Throughput: " << blockingThroughput << " ops/sec\n\n";
  }

  // 성능 차이를 퍼센트로 계산
  double timeImprovement = ((lockFreeTime / blockingTime) - 1) * 100.0;

  std::cout << "Performance Comparison:\n";
  std::cout << "- Blocking Vector is " << std::fixed << std::setprecision(2)
                  << timeImprovement << "% faster\n";
  std::cout << "---------------------------------------------\n";
}

int main() {

  std::cout << "=== Performance Test ===\n";

  runPerformanceTest<8>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<32>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<64>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<128>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<512>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<1024>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<2048>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<4096>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<8192>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<10 * 1024>(testCount);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  runPerformanceTest<20 * 1024>(testCount);

  return 0;
}

