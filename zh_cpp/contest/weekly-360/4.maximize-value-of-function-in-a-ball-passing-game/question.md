# [8027. 在传球游戏中最大化函数值][link] (Medium)

[link]: https://leetcode.cn/contest/weekly-contest-360/problems/maximize-value-of-function-in-a-ball-passing-game/


              <p>给你一个长度为 <code>n</code> 下标从 <strong>0</strong> 开始的整数数组 <code>receiv
er</code> 和一个整数 <code>k</code> 。</p>

<p>总共有 <code>n</code> 名玩家，玩家 <strong>编号</strong> 互不相同，且为 <code>[0, n - 1]</code> 
中的整数。这些玩家玩一个传球游戏，<code>receiver[i]</code> 表示编号为 <code>i</code> 的玩家会传球给
编号为 <code>receiver[i]</code> 的玩家。玩家可以传球给自己，也就是说 <code>receiver[i]</code> 可能等
于 <code>i</code> 。</p>

<p>你需要从 <code>n</code> 名玩家中选择一名玩家作为游戏开始时唯一手中有球的玩家，球会被传 <strong>恰
好</strong> <code>k</code> 次。</p>

<p>如果选择编号为 <code>x</code> 的玩家作为开始玩家，定义函数 <code>f(x)</code> 表示从编号为 <code>x
</code> 的玩家开始，<code>k</code> 次传球内所有接触过球玩家的编号之 <strong>和</strong> ，如果有玩家
多次触球，则 <strong>累加多次</strong> 。换句话说， <code>f(x) = x + receiver[x] + receiver[receiver
[x]] + ... + receiver<sup>(k)</sup>[x]</code> 。</p>

<p>你的任务时选择开始玩家 <code>x</code> ，目的是<strong> 最大化</strong> <code>f(x)</code> 。</p>

<p>请你返回函数的 <strong>最大值</strong> 。</p>

<p><strong>注意：</strong><code>receiver</code> 可能含有重复元素。</p>

<p> </p>

<p><strong class="example">示例 1：</strong></p>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
    <tbody>
        <tr>
            <th style="padding: 5px; border: 1px solid black;">传递次数</th>
            <th style="padding: 5px; border: 1px solid black;">传球者编号</th>
            <th style="padding: 5px; border: 1px solid black;">接球者编号</th>
            <th style="padding: 5px; border: 1px solid black;">x + 所有接球者编号</th>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;"> </td>
            <td style="padding: 5px; border: 1px solid black;"> </td>
            <td style="padding: 5px; border: 1px solid black;"> </td>
            <td style="padding: 5px; border: 1px solid black;">2</td>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;">1</td>
            <td style="padding: 5px; border: 1px solid black;">2</td>
            <td style="padding: 5px; border: 1px solid black;">1</td>
            <td style="padding: 5px; border: 1px solid black;">3</td>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;">2</td>
            <td style="padding: 5px; border: 1px solid black;">1</td>
            <td style="padding: 5px; border: 1px solid black;">0</td>
            <td style="padding: 5px; border: 1px solid black;">3</td>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;">3</td>
            <td style="padding: 5px; border: 1px solid black;">0</td>
            <td style="padding: 5px; border: 1px solid black;">2</td>
            <td style="padding: 5px; border: 1px solid black;">5</td>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;">4</td>
            <td style="padding: 5px; border: 1px solid black;">2</td>
            <td style="padding: 5px; border: 1px solid black;">1</td>
            <td style="padding: 5px; border: 1px solid black;">6</td>
        </tr>
    </tbody>
</table>

<p> </p>

<pre><b>输入：</b>receiver = [2,0,1], k = 4
<b>输出：</b>6
<b>解释：</b>上表展示了从编号为 x = 2 开始的游戏过程。
从表中可知，f(2) 等于 6 。
6 是能得到最大的函数值。
所以输出为 6 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
    <tbody>
        <tr>
            <th style="padding: 5px; border: 1px solid black;">传递次数</th>
            <th style="padding: 5px; border: 1px solid black;">传球者编号</th>
            <th style="padding: 5px; border: 1px solid black;">接球者编号</th>
            <th style="padding: 5px; border: 1px solid black;">x + 所有接球者编号</th>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;"> </td>
            <td style="padding: 5px; border: 1px solid black;"> </td>
            <td style="padding: 5px; border: 1px solid black;"> </td>
            <td style="padding: 5px; border: 1px solid black;">4</td>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;">1</td>
            <td style="padding: 5px; border: 1px solid black;">4</td>
            <td style="padding: 5px; border: 1px solid black;">3</td>
            <td style="padding: 5px; border: 1px solid black;">7</td>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;">2</td>
            <td style="padding: 5px; border: 1px solid black;">3</td>
            <td style="padding: 5px; border: 1px solid black;">2</td>
            <td style="padding: 5px; border: 1px solid black;">9</td>
        </tr>
        <tr>
            <td style="padding: 5px; border: 1px solid black;">3</td>
            <td style="padding: 5px; border: 1px solid black;">2</td>
            <td style="padding: 5px; border: 1px solid black;">1</td>
            <td style="padding: 5px; border: 1px solid black;">10</td>
        </tr>
    </tbody>
</table>

<p> </p>

<pre><b>输入：</b>receiver = [1,1,1,2,3], k = 3
<b>输出：</b>10
<b>解释：</b>上表展示了从编号为 x = 4 开始的游戏过程。
从表中可知，f(4) 等于 10 。
10 是能得到最大的函数值。
所以输出为 10 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
    <li><code>1 &lt;= receiver.length == n &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= receiver[i] &lt;= n - 1</code></li>
    <li><code>1 &lt;= k &lt;= 10<sup>10</sup></code></li>
</ul>

            
