#### AMD 7945HX / 32G / Linux Mint 21.3(Ubuntu 22.04)
<table style="width: 100%; border-collapse: collapse;">
<thead>
<tr>
<th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Block Size</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Execution Time (seconds)</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Throughput (ops/sec)</th>
<th colspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">% Faster than BoostLockFree</th>
</tr>
<tr>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
</tr>
</thead>
<tbody>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.912</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.222</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.175</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.43M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.12M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">57.23M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1214.16%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1566.73%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">16 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.898</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.245</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.222</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.45M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">40.86M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">44.97M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1083.86%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1203.11%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">32 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.074</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.300</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.220</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.25M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">33.38M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.38M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">926.21%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1295.12%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">64 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.093</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.399</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.218</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.23M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">25.08M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.82M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">675.66%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1317.20%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">128 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.056</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.664</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.232</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.27M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">15.07M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">43.08M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">360.58%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1216.81%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">256 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.089</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.026</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.298</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.24M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.74M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">33.53M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">200.95%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">935.59%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">512 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.443</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.252</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.623</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.90M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.99M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">16.06M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">175.06%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">453.10%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">1024 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.687</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.415</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.796</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.71M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.14M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.56M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">52.68%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">362.88%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">2048 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.244</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.707</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.160</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.91M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.69M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">8.62M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">93.69%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">352.11%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">4096 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.872</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.138</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.598</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.27M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.95M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.26M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">53.19%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">392.52%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8192 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.436</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.147</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.176</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.80M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.09M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.60M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">35.95%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">471.46%</td>
</tr>
</tbody>
</table>
<br>
#### AMD 8845HS / 16G / Linux Mint 22.1(Ubuntu 24.04)
<table style="width: 100%; border-collapse: collapse;">
<thead>
<tr>
<th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Block Size</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Execution Time (seconds)</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Throughput (ops/sec)</th>
<th colspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">% Faster than BoostLockFree</th>
</tr>
<tr>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
</tr>
</thead>
<tbody>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.390</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.211</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.197</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.19M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">47.50M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">50.88M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">560.41%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">607.41%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">16 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.372</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.218</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.192</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.29M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.86M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">52.18M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">529.18%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">616.00%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">32 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.330</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.285</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.214</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.52M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">35.08M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">46.83M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">366.57%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">522.82%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">64 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.372</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.387</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.172</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.29M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">25.82M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">58.05M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">254.33%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">696.47%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">128 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.360</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.653</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.202</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.35M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">15.31M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">49.40M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">108.19%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">571.93%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">256 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.432</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.892</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.249</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.98M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">11.21M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">40.10M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">60.60%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">474.45%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">512 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.481</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.073</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.490</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.75M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.32M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">20.42M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">38.00%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">202.37%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">1024 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.691</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.507</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.607</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.91M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.64M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">16.48M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.24%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">178.83%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">2048 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.337</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.341</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.794</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.28M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.27M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.59M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">-0.14%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">194.30%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">4096 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.286</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.565</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.080</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.89M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.81M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.26M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">48.29%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">389.62%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8192 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">10.973</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.191</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.580</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.91M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.39M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.33M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">52.59%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">594.30%</td>
</tr>
</tbody>
</table>
