<table style="width: 100%; border-collapse: collapse;">
<thead>
<tr>
<th rowspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Block Size</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Execution Time (seconds)</th>
<th colspan="3" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">Throughput (ops/sec)</th>
<th colspan="2" style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">% Faster (vs BoostLockFree)</th>
</tr>
<tr>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BoostLockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">MoodyCamel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BlockingVector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BoostLockFree</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">MoodyCamel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BlockingVector</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">MoodyCamel</th>
<th style="border: 1px solid #ddd; padding: 8px; background-color: #f5f5f5; text-align: center;">BlockingVector</th>
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
