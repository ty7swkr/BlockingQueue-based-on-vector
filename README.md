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
            <th rowspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Block Size</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Execution Time (seconds)</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Throughput (ops/sec)</th>
            <th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">% Faster</th>
        </tr>
        <tr>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">BlockingVector</th>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">BlockingVector</th>
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

#### AMD 7945HX / 32G / Linux Mint 21.3(Ubuntu 22.04), Last updated 05.23.2025
<table style="width: 100%; border-collapse: collapse;">
    <thead>
        <tr>
            <th rowspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Block Size</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Execution Time (seconds)</th>
            <th colspan="2" style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">Throughput (ops/sec)</th>
            <th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">% Faster</th>
        </tr>
        <tr>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">BlockingVector</th>
            <th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5;">BoostLockFree</th>
            <th style="border: 1px solid #ddd; border-right: 2px solid #bbb; padding: 8px; background-color: #f5f5f5;">BlockingVector</th>
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

#### Special Notes
There is a notable difference in performance between the i9-9900K and AMD 7945HX. It is a simple comparison, but if you look at the lock-free, there is a difference in CPU, and you can see that Intel is about 3 times faster than AMD.
<br><br>
