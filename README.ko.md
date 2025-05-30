*Read this in other languages: [English](README.md)*

# BlockingVector Queue
이 소스는 boost::lockfree::queue 대비 더 빠른 std::vector기반의 Producer-Consumer Pattern 용 큐이며 아래 벤치마크는 더욱 인상적일 것입니다.
C++ 표준라이브러리를 그대로 사용하였으며 코드는 굉장히 간단(signal+blockingvector = 약 500라인, 쓰레드 제외)합니다.
<br><br>
락프리큐도 CAS 기반의 경쟁을 사용하므로, 락프리큐가 항상 최선의 선택이 아닐 수 있습니다. 이 코드는 생산자-소비자 패턴에서는 락프리큐의 훌륭한 대체 방법이 될 것이라고 생각됩니다. 따라서 진행 중인 프로젝트에서 어떤 구현 방법이 적합한지는 성능-디버깅-구현방법-의존성-제약조건 등의 트레이드오프 관계를 고려하여 선택할 필요가 있다는 것이 제 생각입니다.
<br><br>
이 소스를 그대로 사용해도 좋지만(MIT라이센스), 구현이 간단하므로 해당 소스를 참고하여 진행중인 프로젝트에 어울리는 방법론으로 구현할 수 있다고 생각합니다.
<br><br>

### 참조
<a href="https://cplusplus.tistory.com/entry/C-Lockfree-Queue%EA%B0%80-%ED%95%AD%EC%83%81-%EC%A2%8B%EC%9D%80-%EC%84%A0%ED%83%9D%EC%9D%BC%EA%B9%8C" target="_blank">Lock-free Queue가 항상 좋은 선택일까?</a>
<br><br>

### 특징
- C++ 표준 라이브러리만을 사용한 약 500라인의 간단한 구현체
- std::vector를 래핑하여 블로킹 기능을 추가한 큐 컨테이너
- 간단한 코드 구조로 디버깅이 용이
- 저장타입에 제한 없음(std::vector 저장타입 제한과 동일)
- std::vector 기반으로 메모리 할당이 자유로움
- 단일 생산자-소비자(1:1) 패턴에 최적화 (다중 생산자-소비자(1:N, N:N) 패턴은 별도의 관리 객체(중간 관리 클래스) 구현 필요)
- 대기시 CPU점유율 0 %

### 요구사항
- C++11을 지원하는 컴파일러.

### 짧은 벤치마크
- AMD 7945HX 와 i9-9900K CPU @ 3.60GHz에서 각각 테스트 되었습니다.
- boost::lockfree::queue와 BlockingVector는 각 블럭별로 100000개의 예비 버퍼.
- 블럭사이즈별로 Producer-Consumer가 1:1로 주고 받은 결과입니다.
- 블럭은 8,32,64,128,512,1024,2048,4096,8192,10240,20480의 사이즈 별로 10,000,000번 전송 하였습니다.
- 구현물은 src/main.cpp에 작성되어 있습니다.
- 벤치마크 소스 및 표는 Claude(sonnet 3.5)를 이용하여 작성하였습니다.
- 아래는 5회 실행 후 6회째 결과입니다.

#### i9-9900K CPU @ 3.60GHz / 32G / Rocky Linux 9.4
<table style="width: 100%; border-collapse: collapse;">
    <thead>
        <tr>
            <th rowspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Block Size</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Execution Time (seconds)</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Throughput (ops/sec)</th>
            <th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">% Faster</th>
        </tr>
        <tr>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">Boost<br>LockFree Queue</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Blocking Vector</th>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">Boost<br>LockFree Queue</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Blocking Vector</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1.500</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.402</td>
            <td style="border: 1px solid #ddd; padding: 8px;">6,664,725</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">24,886,699</td>
            <td style="border: 1px solid #ddd; padding: 8px;">273.41%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">32 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1.501</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.402</td>
            <td style="border: 1px solid #ddd; padding: 8px;">6,663,983</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">24,853,114</td>
            <td style="border: 1px solid #ddd; padding: 8px;">272.95%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">64 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1.547</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.417</td>
            <td style="border: 1px solid #ddd; padding: 8px;">6,465,314</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">23,995,230</td>
            <td style="border: 1px solid #ddd; padding: 8px;">271.14%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">128 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1.557</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.452</td>
            <td style="border: 1px solid #ddd; padding: 8px;">6,420,936</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">22,118,989</td>
            <td style="border: 1px solid #ddd; padding: 8px;">244.48%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">512 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1.767</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.945</td>
            <td style="border: 1px solid #ddd; padding: 8px;">5,659,428</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">10,584,315</td>
            <td style="border: 1px solid #ddd; padding: 8px;">87.02%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1024 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">2.049</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1.123</td>
            <td style="border: 1px solid #ddd; padding: 8px;">4,879,431</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8,905,555</td>
            <td style="border: 1px solid #ddd; padding: 8px;">82.51%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2048 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">2.418</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1.898</td>
            <td style="border: 1px solid #ddd; padding: 8px;">4,134,951</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">5,269,227</td>
            <td style="border: 1px solid #ddd; padding: 8px;">27.43%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">4096 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.195</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2.630</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,130,336</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3,801,753</td>
            <td style="border: 1px solid #ddd; padding: 8px;">21.45%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8192 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">5.519</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3.499</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1,811,948</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2,857,988</td>
            <td style="border: 1px solid #ddd; padding: 8px;">57.73%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">10240 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">6.463</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3.744</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1,547,197</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2,671,151</td>
            <td style="border: 1px solid #ddd; padding: 8px;">72.64%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">20480 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">14.012</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">7.395</td>
            <td style="border: 1px solid #ddd; padding: 8px;">713,652</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1,352,230</td>
            <td style="border: 1px solid #ddd; padding: 8px;">89.48%</td>
        </tr>
    </tbody>
</table>

#### AMD 7945HX / 32G / Linux Mint 21.3(Ubuntu 22.04), Last updated 05.23.2024
<table style="width: 100%; border-collapse: collapse;">
    <thead>
        <tr>
            <th rowspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Block Size</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Execution Time (seconds)</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Throughput (ops/sec)</th>
            <th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">% Faster</th>
        </tr>
        <tr>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">LockFree Queue</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Blocking Vector</th>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">LockFree Queue</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Blocking Vector</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.071</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.218</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,256,438</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">45,897,923</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1309.45%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">32 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.045</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.235</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,284,112</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">42,520,299</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1194.73%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">64 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.105</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.256</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,220,681</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">39,063,747</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1112.90%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">128 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.112</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.268</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,213,384</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">37,340,571</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1062.03%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">512 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.509</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.660</td>
            <td style="border: 1px solid #ddd; padding: 8px;">2,849,825</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">15,144,245</td>
            <td style="border: 1px solid #ddd; padding: 8px;">431.41%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1024 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.800</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.733</td>
            <td style="border: 1px solid #ddd; padding: 8px;">2,631,334</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">13,649,849</td>
            <td style="border: 1px solid #ddd; padding: 8px;">418.74%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2048 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">5.165</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1.174</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1,936,289</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8,514,377</td>
            <td style="border: 1px solid #ddd; padding: 8px;">339.73%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">4096 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">8.417</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1.567</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1,188,117</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">6,382,733</td>
            <td style="border: 1px solid #ddd; padding: 8px;">437.21%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8192 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">12.478</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2.607</td>
            <td style="border: 1px solid #ddd; padding: 8px;">801,413</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3,835,892</td>
            <td style="border: 1px solid #ddd; padding: 8px;">378.64%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">10240 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">13.921</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3.408</td>
            <td style="border: 1px solid #ddd; padding: 8px;">718,332</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2,934,279</td>
            <td style="border: 1px solid #ddd; padding: 8px;">308.49%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">20480 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">22.029</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">5.672</td>
            <td style="border: 1px solid #ddd; padding: 8px;">453,957</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1,762,968</td>
            <td style="border: 1px solid #ddd; padding: 8px;">288.36%</td>
        </tr>
    </tbody>
</table>
<br>

#### 특이사항
i9-9900K와 AMD 7945HX의 성능차이가 두드러진 특징이 있습니다. 단순 비교이나 락프리를 보면 물론 CPU 차이가 있지만 어림잡아 인텔에서는 AMD보다 약 3배정도 빠른것을 확인할 수 있습니다.

