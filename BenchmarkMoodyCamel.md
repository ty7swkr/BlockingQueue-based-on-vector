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
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.007</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.214</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.195</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.17M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">44.51M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">48.80M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1303.28%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1438.49%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">16 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.028</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.234</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.219</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.15M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">40.83M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">43.57M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1196.26%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1283.35%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">32 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.968</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.295</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.228</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.21M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">32.31M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">41.83M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">905.48%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1201.66%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">64 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.936</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.314</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.216</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.25M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">30.36M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">44.14M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">834.72%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1258.71%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">128 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.127</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.882</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.208</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.05M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">10.81M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.89M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">254.38%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1404.72%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">256 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.106</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.253</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.232</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.07M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.61M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">41.03M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">147.80%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1236.42%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">512 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.467</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.725</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.617</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.75M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.53M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">15.45M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">101.02%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">461.68%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">1024 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.701</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.386</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.747</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.58M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.00M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.76M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">55.09%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">395.25%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">2048 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.126</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.088</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.052</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.86M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.09M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.06M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">66.00%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">387.17%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">4096 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">8.443</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.090</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.519</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.13M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.87M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.28M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">65.89%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">455.67%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8192 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.445</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.755</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.479</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.77M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.23M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.85M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">60.49%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">402.07%</td>
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
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.197</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.213</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.192</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.97M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">44.86M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">49.64M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">463.18%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">523.18%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">16 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.381</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.219</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.228</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.91M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">43.56M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">41.85M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">530.89%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">506.11%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">32 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.313</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.305</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.204</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.26M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">31.30M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">46.74M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">331.02%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">543.57%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">64 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.371</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.427</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.204</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.96M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">22.32M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">46.74M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">220.86%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">571.85%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">128 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.395</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.697</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.212</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.84M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">13.68M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.07M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">100.06%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">559.24%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">256 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.480</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.942</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.275</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.44M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">10.12M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">34.67M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">57.08%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">437.95%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">512 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.539</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.054</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.513</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.20M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.05M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">18.57M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.99%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">199.66%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">1024 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.663</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.540</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.631</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.73M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.19M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">15.10M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">8.02%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">163.37%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">2048 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.360</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.414</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.807</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.04M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.95M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">11.81M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">-2.21%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">192.32%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">4096 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.448</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.743</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.088</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.75M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.55M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">8.76M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">45.55%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">400.57%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8192 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">10.585</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.376</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.603</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.90M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.01M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.95M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">345.47%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">560.40%</td>
</tr>
</tbody>
</table>
