/*
Problem Statement
There are N robots numbered 1 to N placed on a number line.Robot i is placed at coordinate Xi.When activated, it will travel the distance of Di in the positive direction, and then it will be removed from the number line.All the robots move at the same speed, and their sizes are ignorable.

Takahashi, who is a mischievous boy, can do the following operation any number of times(possibly zero) as long as there is a robot remaining on the number line.

Choose a robotand activate it.This operation cannot be done when there is a robot moving.
While Robot i is moving, if it touches another robot j that is remaining in the range[Xi, Xi + Di) on the number line, Robot j also gets activatedand starts moving.This process is repeated recursively.

How many possible sets of robots remaining on the number line are there after Takahashi does the operation some number of times ? Compute this count modulo 998244353, since it can be enormous.

문제 명세서
숫자 라인에는 1부터 N까지 번호가 매겨진 N개의 로봇들이 있다. 로봇 i는 Xi 좌표에 위치한다. 활성화되면 Di의 거리를 양방향으로 이동한 다음 번호선에서 제거된다. 모든 로봇은 같은 속도로 움직이며, 그 크기는 무식하다.

장난꾸러기 소년인 다카하시씨는 번호선에 로봇이 남아 있는 한 얼마든지 (아마 0으로) 다음과 같은 작전을 수행할 수 있다.

로봇을 선택하고 활성화하십시오. 로봇이 움직이면 이 작업을 수행할 수 없다.
로봇 i가 움직이는 동안 숫자 라인에서 [Xi,Xi+Di] 범위에 남아있는 다른 로봇 j에 닿으면 로봇 j도 활성화되어 움직이기 시작한다. 이 과정은 반복적으로 반복된다.

다카하시가 몇 번인가 수술을 하고 나면 번호선에 남아 있을 수 있는 로봇 세트가 몇 개나 되는가? 이 계산 모듈로는 엄청날 수 있으므로 계산한다.
*/

