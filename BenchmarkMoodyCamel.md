#### AMD 7945HX / 32G / Linux Mint 21.3(Ubuntu 22.04)
<table style="width: 100%; border-collapse: collapse;">
<thead>
<tr>
<th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Block Size</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Execution Time (seconds)</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Throughput (ops/sec)</th>
<th colspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">% Faster then BoostLockFree</th>
</tr>
<tr>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel(token)</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel(token)</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel(token)</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
</tr>
</thead>
<tbody>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">3.095</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.170</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.171</td>
<td style="border: 1px solid #ddd; padding: 8px;">3,231,286</td>
<td style="border: 1px solid #ddd; padding: 8px;">58,864,447</td>
<td style="border: 1px solid #ddd; padding: 8px;">58,488,155</td>
<td style="border: 1px solid #ddd; padding: 8px;">1721.70%</td>
<td style="border: 1px solid #ddd; padding: 8px;">1710.06%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">32 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">3.115</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.306</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.235</td>
<td style="border: 1px solid #ddd; padding: 8px;">3,210,317</td>
<td style="border: 1px solid #ddd; padding: 8px;">32,729,520</td>
<td style="border: 1px solid #ddd; padding: 8px;">42,533,389</td>
<td style="border: 1px solid #ddd; padding: 8px;">919.51%</td>
<td style="border: 1px solid #ddd; padding: 8px;">1224.90%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">64 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">3.132</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.407</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.256</td>
<td style="border: 1px solid #ddd; padding: 8px;">3,193,217</td>
<td style="border: 1px solid #ddd; padding: 8px;">24,582,899</td>
<td style="border: 1px solid #ddd; padding: 8px;">39,005,525</td>
<td style="border: 1px solid #ddd; padding: 8px;">669.85%</td>
<td style="border: 1px solid #ddd; padding: 8px;">1121.51%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">128 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">3.188</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.674</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.217</td>
<td style="border: 1px solid #ddd; padding: 8px;">3,136,581</td>
<td style="border: 1px solid #ddd; padding: 8px;">14,826,665</td>
<td style="border: 1px solid #ddd; padding: 8px;">46,130,617</td>
<td style="border: 1px solid #ddd; padding: 8px;">372.70%</td>
<td style="border: 1px solid #ddd; padding: 8px;">1370.73%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">512 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">3.542</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.352</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.817</td>
<td style="border: 1px solid #ddd; padding: 8px;">2,823,434</td>
<td style="border: 1px solid #ddd; padding: 8px;">7,395,018</td>
<td style="border: 1px solid #ddd; padding: 8px;">12,241,323</td>
<td style="border: 1px solid #ddd; padding: 8px;">161.92%</td>
<td style="border: 1px solid #ddd; padding: 8px;">333.56%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">1024 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">3.689</td>
<td style="border: 1px solid #ddd; padding: 8px;">2.281</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.787</td>
<td style="border: 1px solid #ddd; padding: 8px;">2,710,478</td>
<td style="border: 1px solid #ddd; padding: 8px;">4,383,978</td>
<td style="border: 1px solid #ddd; padding: 8px;">12,712,296</td>
<td style="border: 1px solid #ddd; padding: 8px;">61.74%</td>
<td style="border: 1px solid #ddd; padding: 8px;">369.01%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">2048 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">5.124</td>
<td style="border: 1px solid #ddd; padding: 8px;">2.828</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.189</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,951,472</td>
<td style="border: 1px solid #ddd; padding: 8px;">3,535,485</td>
<td style="border: 1px solid #ddd; padding: 8px;">8,413,526</td>
<td style="border: 1px solid #ddd; padding: 8px;">81.17%</td>
<td style="border: 1px solid #ddd; padding: 8px;">331.14%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">4096 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">8.563</td>
<td style="border: 1px solid #ddd; padding: 8px;">5.194</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.673</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,167,764</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,925,254</td>
<td style="border: 1px BoostLockFreesolid #ddd; padding: 8px;">5,978,590</td>
<td style="border: 1px solid #ddd; padding: 8px;">64.87%</td>
<td style="border: 1px solid #ddd; padding: 8px;">411.97%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8192 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">11.330</td>
<td style="border: 1px solid #ddd; padding: 8px;">7.605</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.737</td>
<td style="border: 1px solid #ddd; padding: 8px;">882,613</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,314,964</td>
<td style="border: 1px solid #ddd; padding: 8px;">5,755,859</td>
<td style="border: 1px solid #ddd; padding: 8px;">48.99%</td>
<td style="border: 1px solid #ddd; padding: 8px;">552.14%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">10240 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">15.315</td>
<td style="border: 1px solid #ddd; padding: 8px;">9.289</td>
<td style="border: 1px solid #ddd; padding: 8px;">5.292</td>
<td style="border: 1px solid #ddd; padding: 8px;">652,939</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,076,490</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,889,468</td>
<td style="border: 1px solid #ddd; padding: 8px;">64.87%</td>
<td style="border: 1px solid #ddd; padding: 8px;">189.38%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">20480 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">22.746</td>
<td style="border: 1px solid #ddd; padding: 8px;">18.003</td>
<td style="border: 1px solid #ddd; padding: 8px;">5.730</td>
<td style="border: 1px solid #ddd; padding: 8px;">439,646</td>
<td style="border: 1px solid #ddd; padding: 8px;">555,454</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,745,167</td>
<td style="border: 1px solid #ddd; padding: 8px;">26.34%</td>
<td style="border: 1px solid #ddd; padding: 8px;">296.95%</td>
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
<th colspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">% Faster then BoostLockFree</th>
</tr>
<tr>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel(token)</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Boost<br>LockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel(token)</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Moody<br>Camel(token)</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Blocking<br>Vector</th>
</tr>
</thead>
<tbody>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.304</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.206</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.185</td>
<td style="border: 1px solid #ddd; padding: 8px;">7,670,029</td>
<td style="border: 1px solid #ddd; padding: 8px;">48,560,732</td>
<td style="border: 1px solid #ddd; padding: 8px;">54,083,311</td>
<td style="border: 1px solid #ddd; padding: 8px;">533.12%</td>
<td style="border: 1px solid #ddd; padding: 8px;">605.13%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">16 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.296</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.224</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.200</td>
<td style="border: 1px solid #ddd; padding: 8px;">7,713,411</td>
<td style="border: 1px solid #ddd; padding: 8px;">44,732,532</td>
<td style="border: 1px solid #ddd; padding: 8px;">50,094,061</td>
<td style="border: 1px solid #ddd; padding: 8px;">479.93%</td>
<td style="border: 1px solid #ddd; padding: 8px;">549.44%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">32 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.249</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.281</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.195</td>
<td style="border: 1px solid #ddd; padding: 8px;">8,005,829</td>
<td style="border: 1px solid #ddd; padding: 8px;">35,556,286</td>
<td style="border: 1px solid #ddd; padding: 8px;">51,242,620</td>
<td style="border: 1px solid #ddd; padding: 8px;">344.13%</td>
<td style="border: 1px solid #ddd; padding: 8px;">540.07%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">64 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.297</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.398</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.199</td>
<td style="border: 1px solid #ddd; padding: 8px;">7,707,538</td>
<td style="border: 1px solid #ddd; padding: 8px;">25,096,137</td>
<td style="border: 1px solid #ddd; padding: 8px;">50,199,081</td>
<td style="border: 1px solid #ddd; padding: 8px;">225.61%</td>
<td style="border: 1px solid #ddd; padding: 8px;">551.30%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">128 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.277</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.621</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.182</td>
<td style="border: 1px solid #ddd; padding: 8px;">7,831,406</td>
<td style="border: 1px solid #ddd; padding: 8px;">16,094,598</td>
<td style="border: 1px solid #ddd; padding: 8px;">54,890,857</td>
<td style="border: 1px solid #ddd; padding: 8px;">105.51%</td>
<td style="border: 1px solid #ddd; padding: 8px;">600.91%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">512 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.512</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.840</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.514</td>
<td style="border: 1px solid #ddd; padding: 8px;">6,614,812</td>
<td style="border: 1px solid #ddd; padding: 8px;">11,899,474</td>
<td style="border: 1px solid #ddd; padding: 8px;">19,442,277</td>
<td style="border: 1px solid #ddd; padding: 8px;">79.89%</td>
<td style="border: 1px solid #ddd; padding: 8px;">193.92%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">1024 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.654</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.532</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.600</td>
<td style="border: 1px solid #ddd; padding: 8px;">6,045,017</td>
<td style="border: 1px solid #ddd; padding: 8px;">6,527,163</td>
<td style="border: 1px solid #ddd; padding: 8px;">16,661,796</td>
<td style="border: 1px solid #ddd; padding: 8px;">7.98%</td>
<td style="border: 1px solid #ddd; padding: 8px;">175.63%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">2048 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">2.358</td>
<td style="border: 1px solid #ddd; padding: 8px;">2.404</td>
<td style="border: 1px solid #ddd; padding: 8px;">0.758</td>
<td style="border: 1px solid #ddd; padding: 8px;">4,240,270</td>
<td style="border: 1px solid #ddd; padding: 8px;">4,159,582</td>
<td style="border: 1px solid #ddd; padding: 8px;">13,185,969</td>
<td style="border: 1px solid #ddd; padding: 8px;">-1.90%</td>
<td style="border: 1px solid #ddd; padding: 8px;">210.97%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">4096 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">5.366</td>
<td style="border: 1px solid #ddd; padding: 8px;">3.631</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.037</td>
<td style="border: 1px solid #ddd; padding: 8px;">1,863,542</td>
<td style="border: 1px solid #ddd; padding: 8px;">2,754,200</td>
<td style="border: 1px solid #ddd; padding: 8px;">9,640,382</td>
<td style="border: 1px solid #ddd; padding: 8px;">47.79%</td>
<td style="border: 1px solid #ddd; padding: 8px;">417.31%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">8192 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">10.526</td>
<td style="border: 1px solid #ddd; padding: 8px;">4.993</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.571</td>
<td style="border: 1px solid #ddd; padding: 8px;">949,992</td>
<td style="border: 1px solid #ddd; padding: 8px;">2,002,890</td>
<td style="border: 1px solid #ddd; padding: 8px;">6,364,319</td>
<td style="border: 1px solid #ddd; padding: 8px;">110.83%</td>
<td style="border: 1px solid #ddd; padding: 8px;">569.93%</td>
</tr>
<tr>
<td style="border: 1px solid #ddd; padding: 8px;">10240 bytes</td>
<td style="border: 1px solid #ddd; padding: 8px;">13.984</td>
<td style="border: 1px solid #ddd; padding: 8px;">2.790</td>
<td style="border: 1px solid #ddd; padding: 8px;">1.818</td>
<td style="border: 1px solid #ddd; padding: 8px;">715,096</td>
<td style="border: 1px solid #ddd; padding: 8px;">3,584,174</td>
<td style="border: 1px solid #ddd; padding: 8px;">5,500,784</td>
<td style="border: 1px solid #ddd; padding: 8px;">401.22%</td>
<td style="border: 1px solid #ddd; padding: 8px;">669.24%</td>
</tr>
</tbody>
</table>
