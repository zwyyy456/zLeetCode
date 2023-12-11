# [8021. 使子序列的和等于目标的最少操作次数][link] (Medium)

[link]: https://leetcode.cn/contest/weekly-contest-360/problems/minimum-operations-to-form-subsequence-with-target-sum/


              <p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，它包含 <strong>非
负</strong> 整数，且全部为 <code>2</code> 的幂，同时给你一个整数 <code>target</code> 。</p>

<p>一次操作中，你必须对数组做以下修改：</p>

<ul>
    <li>选择数组中一个元素 <code>nums[i]</code> ，满足 <code>nums[i] &gt; 1</code> 。</li>
    <li>将 <code>nums[i]</code> 从数组中删除。</li>
    <li>在 <code>nums</code> 的 <strong>末尾</strong> 添加 <strong>两个</strong> 数，值都为 <code>nu
ms[i] / 2</code> 。</li>
</ul>

<p>你的目标是让 <code>nums</code> 的一个 <strong>子序列</strong> 的元素和等于 <code>target</code> ，
请你返回达成这一目标的 <strong>最少操作次数</strong> 。如果无法得到这样的子序列，请你返回 <code>-1</
code> 。</p>

<p>数组中一个 <strong>子序列</strong> 是通过删除原数组中一些元素，并且不改变剩余元素顺序得到的剩余数
组。</p>

<p> </p>

<p><strong class="example">示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,8], target = 7
<b>输出：</b>1
<b>解释：</b>第一次操作中，我们选择元素 nums[2] 。数组变为 nums = [1,2,4,4] 。
这时候，nums 包含子序列 [1,2,4] ，和为 7 。
无法通过更少的操作得到和为 7 的子序列。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,32,1,2], target = 12
<b>输出：</b>2
<b>解释：</b>第一次操作中，我们选择元素 nums[1] 。数组变为 nums = [1,1,2,16,16] 。
第二次操作中，我们选择元素 nums[3] 。数组变为 nums = [1,1,2,16,8,8] 。
这时候，nums 包含子序列 [1,1,2,8] ，和为 12 。
无法通过更少的操作得到和为 12 的子序列。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,32,1], target = 35
<b>输出：</b>-1
<b>解释：</b>无法得到和为 35 的子序列。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
    <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
    <li><code>1 &lt;= nums[i] &lt;= 2<sup>30</sup></code></li>
    <li><code>nums</code> 只包含非负整数，且均为 2 的幂。</li>
    <li><code>1 &lt;= target &lt; 2<sup>31</sup></code></li>
</ul>

            
