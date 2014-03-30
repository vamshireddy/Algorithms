parents = {}
graph = {}

import sys
sys.setrecursionlimit(100000)

def create_demo_graph(graph):
	graph[1] = [[2],[3]]
	graph[2] = [[4,3],[1]]
	graph[3] = [[9,10,1],[2]]
	graph[4] = [[6,5],[2]]
	graph[5] = [[6],[4,9,7]]
	graph[6] = [[7],[4,5]]
	graph[7] = [[5],[6,8]]
	graph[8] = [[7],[9,11]]
	graph[9] = [[8,11],[3,10]]
	graph[10] = [[9],[3,11]]
	graph[11] = [[10],[9,8]]

def create_graph(graph):
	ifile = open("/home/vamshi/Desktop/Graphs/SCC/SCC.txt","r")
	p = []
	while True:
		q = ifile.readline()
		if q=="":
			break
		q = q[:-2]
		mid = q.find(" ")
		first = int(q[:mid])
		last = int(q[mid+1:])
		if first not in graph:
			graph[first] = [[],[]]
		if last not in graph:
			graph[last] = [[],[]]	
		graph[first][0].append(last)
		graph[last][1].append(first)
#		print " Edge ",first," ",last," Added "

create_graph(graph)
print "Graph created!!"
k = graph.keys()
k.reverse()
l = []
def dfs(graph):
	for i in k:
		if i not in parents:
			parents[i] = None
			dfs_visit(i)
stack = []
def dfs_visit(vertex):
	stack.append(vertex)
	while len(stack)!=0:
		try:
			v = stack[len(stack)-1]
		except:
			break
		flag = 0
		for i in graph[v][1]:
			if i not in parents:
				stack.append(i)
				parents[i] = v
				flag = 1
		if flag == 0:
			stack.pop()
			l.append(v)

dfs(graph)
l.reverse()
parents = {}
stack = []
count_list = []
def d(graph):
	for i in l:
		if i not in parents:
			parents[i] = None
			count_list.append(df(i))
def df(vertex):
	stack.append(vertex)
	count = 0
	x = []
	while len(stack)!=0:
		try:
			v = stack[len(stack)-1]
		except:
			break
		flag = 0
		for i in graph[v][0]:
			if i not in parents:
				stack.append(i)
				parents[i] = v
				flag = 1
		if flag==0:
			x.append(stack.pop())
			count+=1
	print x
	return count

d(graph)
count_list.sort()
print count_list
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

