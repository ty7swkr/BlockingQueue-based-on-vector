*Read this in other languages: [한국어](README.ko.md)*

# BlockingVector Queue
A Producer-Consumer Pattern queue implemented based on std::vector. It shows faster performance than boost::lockfree::queue, which you can verify in the benchmark results below. It only uses the c++ 11 standard library, with a simple codebase (signal+blockingvector is about 500 lines, excluding thread code).
<br><br>
Since lockfree-queue uses CAS-based competition, it may not always be the optimal choice. This implementation can serve as an alternative for producer-consumer patterns. When choosing an implementation, consider trade-offs between performance, debugging ease, implementation complexity, dependencies, and constraints for your specific project needs.
<br><br>
This source is available under MIT license. While you can use it as-is, its simple implementation allows you to adapt it to better suit your project's requirements.
<br><br>

### Related Link
<a href="https://cplusplus.tistory.com/entry/C-Lockfree-Queue%EA%B0%80-%ED%95%AD%EC%83%81-%EC%A2%8B%EC%9D%80-%EC%84%A0%ED%83%9D%EC%9D%BC%EA%B9%8C" target="_blank">Is Lock-free Queue Always the Best Choice?</a>
<br><br>

### Features
- Simple implementation of about 500 lines using only the C++ standard library
- Queue container that wraps std::vector and adds blocking functionality
- Easy debugging with a simple code structure
- No restrictions on storage types (same as std::vector storage type restrictions)
- Free memory allocation based on std::vector
- Optimized for a single producer-consumer (1:1) pattern (multiple producer-consumer (1:N, N:N) patterns require a separate management object (intermediate management class) implementation)
- 0% CPU usage when waiting

### BlockingVector.Queue Requirements
- Compiler that supports C++11.

### Test Requirements
- Compiler that supports C++11
- boost lockfree-queue libraries

### Short benchmark
* Test Environment:
  - AMD 7945HX
  - i9-9900K CPU @ 3.60GHz
* Test Configuration:
  - Both boost::lockfree::queue and BlockingVector have 100,000 spare buffers per block
  - 1:1 exchange between Producer and Consumer
  - 10,000,000 transmissions with varying block sizes: 8, 32, 64, 128, 512, 1024, 2048, 4096, 8192, 10240, 20480
  - Note: Test block size 20480 requires 32GB of memory
* Implementation details:
  - Source code available in src/main.cpp
  - Benchmark source and table created using Claude (sonnet 3.5)
  - Results shown are from the 6th run after 5 warm-up runs

#### i9-9900K CPU @ 3.60GHz / 32G / Rocky Linux 9.4
<table style="width: 100%; border-collapse: collapse;">
    <thead>
        <tr>
            <th rowspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">Block Size</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">Execution Time (seconds)</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">Throughput (ops/sec)</th>
            <th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">% Faster</th>
        </tr>
        <tr>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">BlockingVector</th>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">BlockingVector</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.500</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.402</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.66M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">24.89M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">273.41%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">32 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.501</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.402</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.66M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">24.85M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">272.95%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">64 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.547</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.417</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.47M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">24.00M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">271.14%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">128 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.557</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.452</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.42M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">22.12M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">244.48%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">512 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.767</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.945</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.66M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">10.58M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">87.02%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1024 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.049</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">1.123</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.88M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">8.91M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">82.51%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2048 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.418</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">1.898</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.13M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">5.27M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">27.43%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">4096 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.195</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">2.630</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.13M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">3.80M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">21.45%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8192 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.519</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">3.499</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.81M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">2.86M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">57.73%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">10240 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.463</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">3.744</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.55M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">2.67M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">72.64%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">20480 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">14.012</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">7.395</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.71M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">1.35M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">89.48%</td>
        </tr>
    </tbody>
</table>

#### AMD 7945HX / 32G / Linux Mint 21.3(Ubuntu 22.04), Last updated 05.23.2025
<table style="width: 100%; border-collapse: collapse;">
    <thead>
        <tr>
            <th rowspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">Block Size</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">Execution Time (seconds)</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">Throughput (ops/sec)</th>
            <th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">% Faster</th>
        </tr>
        <tr>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">BlockingVector</th>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5; text-align: center;">BlockingVector</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.071</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.218</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.26M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">45.90M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1309.45%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">32 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.045</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.235</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.28M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">42.52M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1194.73%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">64 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.105</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.256</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.22M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">39.06M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1112.90%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">128 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.112</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.268</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.21M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">37.34M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1062.03%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">512 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.509</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.660</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.85M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">15.14M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">431.41%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1024 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.800</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">0.733</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.63M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">13.65M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">418.74%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2048 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.165</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">1.174</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.94M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">8.51M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">339.73%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">4096 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">8.417</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">1.567</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.19M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">6.38M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">437.21%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8192 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.478</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">2.607</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.80M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">3.84M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">378.64%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">10240 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">13.921</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">3.408</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.72M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">2.93M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">308.49%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">20480 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">22.029</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">5.672</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.45M</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; text-align: right;">1.76M</td>
            <td style="border: 1px solid #ddd; padding: 8px; text-align: right;">288.36%</td>
        </tr>
    </tbody>
</table>
<br>

#### Special Notes
There is a notable difference in performance between the i9-9900K and AMD 7945HX. It is a simple comparison, but if you look at the lock-free, there is a difference in CPU, and you can see that Intel is about 3 times faster than AMD.
<br><br>
