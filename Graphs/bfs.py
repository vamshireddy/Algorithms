graph = {}
start = "1"

def create_graph(graph):
	f = open("/home/vamshi/min.txt","r")
	l = f.readlines()
	for i in l:
		temp = i.split("\t")
		temp.remove("\r\n")
		graph[temp[0]] = temp[1:]

def bfs(graph,start):
	levels = {}
	parents = {}
	levels[start] = 0
	parents[start] = None
	
	cur = [start]
	next = []
	count = 0
	while cur:
		for i in cur:
			for j in graph[i]:
				if j not in levels:
					levels[j] = count
					parents[j] = i
					next.append(j)
			cur = next
			next = []
			count+=1
	return levels,parents
levels = {}
parents = {}
def shortest_path(a,b):
	print "Printing shortest path betweeen ",b," and ",a
	levels,parents = bfs(graph,a)
	count = 0
	l = []
	l = [b]
	print b
	next = []
	while l:
		t = parents[l[0]]
		
		if t!=None:
			print t
			next.append(t)
		l = next
		next = []
		count+=1

create_graph(graph)
shortest_path("123","198")
