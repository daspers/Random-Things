# read file to array and matrices
print "Input the file name : "
STDOUT.flush
filename = gets.chomp
inArr = File.readlines(filename)
i = 1
n = inArr[0].to_i
cost = []
for i in 1..n
	tarr = []
	temp = inArr[i].split(" ")
	for item in temp
		tarr.push(item.to_i)
	end
	cost.push(tarr)
end
node = inArr[n+1].to_i

#recusive dp
def solvetsp(dp, pathrec, cost, idx, remset)
	if dp[idx][remset] == nil
		dp[idx][remset] = 1 << 63 + 1<<62
		tpath = []
		for item in remset
			temp = cost[idx][item]+solvetsp(dp, pathrec, cost, item, remset - [item])
			if dp[idx][remset] > temp 
				pathrec[idx][remset] = [item]
				dp[idx][remset] = temp
			elsif dp[idx][remset] == temp
				pathrec[idx][remset].push(item)
			end
		end
	end
	return dp[idx][remset]
end

#print path using backtrack
def printPath(pathrec, idx, remset, path, node)
	if pathrec[idx][remset] == nil
		for item in path
			print (item+1), " -> "
		end
		print (node+1), "\n"
		return
	end
	for item in pathrec[idx][remset]
		printPath(pathrec, item, remset-[item], path+[item], node)
	end
end

#the algorithm start here
dp = Array.new(n){Hash.new}
pathrec = Array.new(n){Hash.new}
#state the basis first and fill the set
remset = []
for i in 0..n-1
	dp[i][[]] = cost[i][node]
	remset.push(i)
end

print "Minimum Cost : ", solvetsp(dp, pathrec, cost, node, remset-[node]), "\n"
puts "Path : "
printPath(pathrec, node, remset-[node], [node], node)