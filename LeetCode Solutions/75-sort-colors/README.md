<h2><a href="https://leetcode.com/problems/sort-colors/">75. Sort Colors</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">Given an array <code style="user-select: auto;">nums</code> with <code style="user-select: auto;">n</code> objects colored red, white, or blue, sort them <strong style="user-select: auto;"><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank" style="user-select: auto;">in-place</a> </strong>so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>

<p style="user-select: auto;">We will use the integers <code style="user-select: auto;">0</code>, <code style="user-select: auto;">1</code>, and <code style="user-select: auto;">2</code> to represent the color red, white, and blue, respectively.</p>

<p style="user-select: auto;">You must solve this problem without using the library's sort function.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> nums = [2,0,2,1,1,0]
<strong style="user-select: auto;">Output:</strong> [0,0,1,1,2,2]
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> nums = [2,0,1]
<strong style="user-select: auto;">Output:</strong> [0,1,2]
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">n == nums.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= n &lt;= 300</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">nums[i]</code> is either <code style="user-select: auto;">0</code>, <code style="user-select: auto;">1</code>, or <code style="user-select: auto;">2</code>.</li>
</ul>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Follow up:</strong>&nbsp;Could you come up with a one-pass algorithm using only&nbsp;constant extra space?</p>
</div>