/*
Problem Statement
There are N robots numbered 1 to N placed on a number line.Robot i is placed at coordinate Xi.When activated, it will travel the distance of Di in the positive direction, and then it will be removed from the number line.All the robots move at the same speed, and their sizes are ignorable.

Takahashi, who is a mischievous boy, can do the following operation any number of times(possibly zero) as long as there is a robot remaining on the number line.

Choose a robotand activate it.This operation cannot be done when there is a robot moving.
While Robot i is moving, if it touches another robot j that is remaining in the range[Xi, Xi + Di) on the number line, Robot j also gets activatedand starts moving.This process is repeated recursively.

How many possible sets of robots remaining on the number line are there after Takahashi does the operation some number of times ? Compute this count modulo 998244353, since it can be enormous.

���� ����
���� ���ο��� 1���� N���� ��ȣ�� �Ű��� N���� �κ����� �ִ�. �κ� i�� Xi ��ǥ�� ��ġ�Ѵ�. Ȱ��ȭ�Ǹ� Di�� �Ÿ��� ��������� �̵��� ���� ��ȣ������ ���ŵȴ�. ��� �κ��� ���� �ӵ��� �����̸�, �� ũ��� �����ϴ�.

�峭�ٷ��� �ҳ��� ��ī�Ͻþ��� ��ȣ���� �κ��� ���� �ִ� �� �󸶵��� (�Ƹ� 0����) ������ ���� ������ ������ �� �ִ�.

�κ��� �����ϰ� Ȱ��ȭ�Ͻʽÿ�. �κ��� �����̸� �� �۾��� ������ �� ����.
�κ� i�� �����̴� ���� ���� ���ο��� [Xi,Xi+Di] ������ �����ִ� �ٸ� �κ� j�� ������ �κ� j�� Ȱ��ȭ�Ǿ� �����̱� �����Ѵ�. �� ������ �ݺ������� �ݺ��ȴ�.

��ī�Ͻð� �� ���ΰ� ������ �ϰ� ���� ��ȣ���� ���� ���� �� �ִ� �κ� ��Ʈ�� �� ���� �Ǵ°�? �� ��� ���δ� ��û�� �� �����Ƿ� ����Ѵ�.
*/

