# import psyco
# psyco.full()

resulto = [];
main = [];
n_el  = raw_input().split("\n");

# for x in range(0,n_el):
# 	main.append(input());

main = map(int, raw_input().split())
temp = 1;

for x in range(0,int(n_el[0])):
	temp = temp * main[x];
	resulto.append(temp);

nu_games,Y = input().split(" ");
count = 0;
while count < int(nu_games[0]):
	a = map(int, raw_input().split())
	# li = input();
	# ri = input();
	# mod = input();
	li = a[0];
	ri = a[1];
	mod = a[2];

	if(li > 1):
		ans = (resulto[ri-1]/resulto[li-2]);
	else:
		ans = resulto[ri-1];

	finalans = ans%mod;
	print(finalans);
	count+=1;
