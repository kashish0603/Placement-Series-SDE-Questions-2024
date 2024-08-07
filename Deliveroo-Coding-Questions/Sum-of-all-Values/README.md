# Deliveroo-SDE-Questions
<h2>Sum of All Values</h2>

<h3>Problem Statement</h3>
<p>N number is given in string format and we have to find the total sum of all values by putting a '+' sign in between string characters.
  
  If string is "123", the result should be the sum of "1+23", "12+3", "1+2+3" and "123" mod 10^9+7.

 <b> Examples: 
 
  Input: </b>
  
  string s = "123"<br>
  
  <b>Output:<br><be></b> 168 

<h3>Approach: </h3>

To solve the problem of finding the sum of all possible values by placing + signs between the characters of a given string, you can use the following approach:
<ol>
<li>Generate All Possible Values: Consider each possible way to insert + signs into the string. For a string of length 𝑛, there are 2^(𝑛−1)possible ways to place '+' signs because each of the 𝑛−1 positions between characters can either have a '+' or not.</li>

<li>Calculate Each Value: For each way of placing '+' signs, calculate the resulting number and sum these values.</li>

<li>Modular Arithmetic: Since the result can be very large, compute the sum modulo 10^9+7.</li>
</ol>
