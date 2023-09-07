# [8015. 距离原点最远的点][link] (Easy)

[link]: https://leetcode.cn/contest/weekly-contest-360/problems/furthest-point-from-origin/


              <p>给你一个长度为 <code>n</code> 的字符串 <code>moves</code> ，该字符串仅由字符 <code>
&#39;L&#39;</code>、<code>&#39;R&#39;</code> 和 <code>&#39;_&#39;</code> 组成。字符串表示你在一条原
点为 <code>0</code> 的数轴上的若干次移动。</p>

<p>你的初始位置就在原点（<code>0</code>），第 <code>i</code> 次移动过程中，你可以根据对应字符选择移
动方向：</p>

<ul>
    <li>如果 <code>moves[i] = &#39;L&#39;</code> 或 <code>moves[i] = &#39;_&#39;</code> ，可以选择向
左移动一个单位距离</li>
    <li>如果 <code>moves[i] = &#39;R&#39;</code> 或 <code>moves[i] = &#39;_&#39;</code> ，可以选择向
右移动一个单位距离</li>
</ul>

<p>移动 <code>n</code> 次之后，请你找出可以到达的距离原点 <strong>最远</strong> 的点，并返回 <strong
>从原点到这一点的距离</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>moves = &#34;L_RL__R&#34;
<strong>输出：</strong>3
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 -3 ，移动的序列为 &#34;LLRLLLR&#34; 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>moves = &#34;_R__LL_&#34;
<strong>输出：</strong>5
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 -5 ，移动的序列为 &#34;LRLLLLL&#34; 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>moves = &#34;_______&#34;
<strong>输出：</strong>7
<strong>解释：</strong>可以到达的距离原点 0 最远的点是 7 ，移动的序列为 &#34;RRRRRRR&#34; 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
    <li><code>1 &lt;= moves.length == n &lt;= 50</code></li>
    <li><code>moves</code> 仅由字符 <code>&#39;L&#39;</code>、<code>&#39;R&#39;</code> 和 <code>&#39
;_&#39;</code> 组成</li>
</ul>

            
