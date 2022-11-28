# [Platinum III] Grid Triangle - 23570 

[문제 링크](https://www.acmicpc.net/problem/23570) 

### 성능 요약

메모리: 2020 KB, 시간: 36 ms

### 분류

많은 조건 분기(case_work), 수학(math)

### 문제 설명

<p>A <em>grid triangle</em> in the 3-dimensional grid system is a triangle of three integral points including the origin $(0,0,0)$ that satisfy the following property:</p>

<blockquote>
<p>There exist three different positive integers $X$, $Y$, $Z$ such that for every pair of the three points of the triangle, you can rotate and translate the cuboid of size $X × Y × Z$ in parallel with the grid system so that the pair are diagonally opposite (and so the farthest way) vertices of the cuboid.</p>
</blockquote>

<p>For instance, the triangle of the three points $(0,0,0)$, $(1,2,3)$, $(-2,3,1)$ is a grid triangle with the cuboid of size $1 × 2 × 3$. More specifically, the two points $(1,2,3)$, $(-2,3,1)$ are the diagonally opposite vertices of the cuboid $\{(x, y, z)| -2 ≤ x ≤ 1, 2 ≤ y ≤ 3, 1 ≤ z ≤ 3\}$ of size $3 × 1 × 2$; the two points $(0,0,0)$, $(1,2,3)$ are the diagonally opposite vertices of the cuboid $\{(x, y, z)|0 ≤ x ≤ 1, 0 ≤ y ≤ 2, 0 ≤ z ≤ 3\}$ of size $1 × 2 × 3$; and the two points $(0,0,0)$, $(-2,3,1)$ are the diagonally opposite vertices of the cuboid $\{(x, y, z)| -2 ≤ x ≤ 0, 0 ≤ y ≤ 3, 0 ≤ z ≤ 1\}$ of size $2 × 3 × 1$. Further, all three cuboids are parallel with the grid system.</p>

<p>Write a program to output the number of grid triangles within a bounded 3-dimenional grid system. The grid system is bounded by three given positive integers, $A$, $B$, $C$, in such a way that all points of grid triangles should be within $\{(x, y, z)| -A ≤ x ≤ A, -B ≤ y ≤ B, -C ≤ z ≤ C\}$.</p>

### 입력 

 <p>Your program is to read from standard input. The input is exactly one line containing three integers, $A$, $B$, $C$ ($1 ≤ A, B, C ≤ 10,000,000$).</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the number of grid triangles in the 3-dimensional grid system bounded by $A$, $B$, $C$.</p>

