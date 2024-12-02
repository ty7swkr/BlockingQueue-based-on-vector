# BlockingVector Queue
이 소스는 boost::lockfree::queue 대비 더 빠른 std::vector기반의 Producer-Consumer Pattern 용 큐이며 아래 벤치마크는 더욱 인상적일 것입니다.
C++ 표준라이브러리를 그대로 사용하였으며 코드는 굉장히 간단(signal+blockingvector = 약 400라인, 쓰레드 제외)합니다.
<br><br>
락프리큐도 CAS 기반의 경쟁을 사용하므로, 락프리큐가 항상 최선의 선택이 아닐 수 있습니다. 이 코드는 생산자-소비자 패턴에서는 락프리큐의 훌륭한 대체 방법이 될 것이라고 생각됩니다. 따라서 진행 중인 프로젝트에서 어떤 구현 방법이 적합한지는 성능-디버깅-구현방법-의존성-제약조건 등의 트레이드오프 관계를 고려하여 선택할 필요가 있다는 것이 제 의견입니다.
<br><br>
이 소스를 그대로 사용해도 괜찮지만(MIT라이센스), 구현이 간단하므로 해당 소스를 참고하여 진행중인 프로젝트에 어울리는 방법론으로 구현할 수 있다고 생각합니다.
<br><br>
### 특징
- C++ 표준 라이브러리만을 사용한 약 400라인의 간단한 구현체
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

#### AMD 7945HX / 32G / Linux Mint 21.3(Ubuntu 22.04)
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
            <td style="border: 1px solid #ddd; padding: 8px;">3.030</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.187</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,300,764</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">53,378,810</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1517.16%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">32 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.032</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.145</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,297,825</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">68,852,801</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1987.82%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">64 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.112</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.185</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,213,364</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">54,181,860</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1586.14%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">128 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.127</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">0.191</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3,198,217</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">52,237,795</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1533.34%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">512 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.572</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1.198</td>
            <td style="border: 1px solid #ddd; padding: 8px;">2,799,225</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8,346,148</td>
            <td style="border: 1px solid #ddd; padding: 8px;">198.16%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1024 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">3.723</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3.319</td>
            <td style="border: 1px solid #ddd; padding: 8px;">2,685,945</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3,012,592</td>
            <td style="border: 1px solid #ddd; padding: 8px;">12.16%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2048 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">4.715</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2.886</td>
            <td style="border: 1px solid #ddd; padding: 8px;">2,120,998</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3,464,513</td>
            <td style="border: 1px solid #ddd; padding: 8px;">63.34%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">4096 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">8.472</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2.825</td>
            <td style="border: 1px solid #ddd; padding: 8px;">1,180,360</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3,540,176</td>
            <td style="border: 1px solid #ddd; padding: 8px;">199.92%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">8192 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">10.934</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2.541</td>
            <td style="border: 1px solid #ddd; padding: 8px;">914,591</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3,935,628</td>
            <td style="border: 1px solid #ddd; padding: 8px;">330.32%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">10240 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">14.105</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">3.759</td>
            <td style="border: 1px solid #ddd; padding: 8px;">708,945</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">2,660,097</td>
            <td style="border: 1px solid #ddd; padding: 8px;">275.22%</td>
        </tr>
        <tr>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">20480 bytes</td>
            <td style="border: 1px solid #ddd; padding: 8px;">21.985</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">5.639</td>
            <td style="border: 1px solid #ddd; padding: 8px;">454,859</td>
            <td style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px;">1,773,483</td>
            <td style="border: 1px solid #ddd; padding: 8px;">289.90%</td>
        </tr>
    </tbody>
</table>
<br>

#### 특이사항
i9-9900K와 AMD 7945HX의 성능차이가 두드러진 특징이 있습니다. 단순 비교이나 락프리를 보면 물론 CPU 차이가 있지만 어림잡아 인텔에서는 AMD보다 약 3배정도 빠른것을 확인할 수 있습니다.

