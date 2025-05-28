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
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.984</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.361</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.275</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.35M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">27.71M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">36.30M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">726.68%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">982.98%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">16 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.830</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.663</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.304</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.53M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">15.08M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">32.89M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">326.93%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">830.94%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">32 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.858</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.513</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.296</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.50M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">19.48M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">33.73M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">456.83%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">864.01%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">64 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.027</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.714</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.290</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.30M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">14.01M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">34.53M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">324.12%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">945.47%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">128 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.969</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.068</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.286</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.37M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.36M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">34.95M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">177.92%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">937.63%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">256 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.611</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.448</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.284</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.83M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.91M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">35.27M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">80.39%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">821.04%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">512 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.560</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.851</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.912</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.81M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.40M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">10.96M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">92.35%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">290.18%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">1024 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.802</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.180</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.677</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.63M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.59M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">14.78M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">74.41%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">461.91%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">2048 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">5.022</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.207</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.374</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.99M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">3.12M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">7.28M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">56.60%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">265.56%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">4096 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">8.223</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.942</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.451</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.22M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.02M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">6.89M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">66.40%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">466.52%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8192 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">12.365</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">9.237</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">2.099</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">0.81M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">1.08M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">4.76M</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">33.87%</td>
<td style="border: 1px solid #ddd; padding: 8px; text-align: right;">488.97%</td>
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
