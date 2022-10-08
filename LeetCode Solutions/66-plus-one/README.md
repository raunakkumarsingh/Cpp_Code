<h2><a href="https://leetcode.com/problems/plus-one/">66. Plus One</a></h2><h3>Easy</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given a <strong style="user-select: auto;">large integer</strong> represented as an integer array <code style="user-select: auto;">digits</code>, where each <code style="user-select: auto;">digits[i]</code> is the <code style="user-select: auto;">i<sup style="user-select: auto;">th</sup></code> digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading <code style="user-select: auto;">0</code>'s.</p>

<p style="user-select: auto;">Increment the large integer by one and return <em style="user-select: auto;">the resulting array of digits</em>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> digits = [1,2,3]
<strong style="user-select: auto;">Output:</strong> [1,2,4]
<strong style="user-select: auto;">Explanation:</strong> The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> digits = [4,3,2,1]
<strong style="user-select: auto;">Output:</strong> [4,3,2,2]
<strong style="user-select: auto;">Explanation:</strong> The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> digits = [9]
<strong style="user-select: auto;">Output:</strong> [1,0]
<strong style="user-select: auto;">Explanation:</strong> The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= digits.length &lt;= 100</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= digits[i] &lt;= 9</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">digits</code> does not contain any leading <code style="user-select: auto;">0</code>'s.</li>
</ul>
</div>