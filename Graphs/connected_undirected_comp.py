graph={}
levels = {}

def create_graph(graph):
	f = open("/home/vamshi/SCC.txt","r")
	l = f.readlines()
	for i in l:
		i = i[:-2]
		i = i.split()
		if int(i[0]) not in graph:
			graph[int(i[0])] = [int(i[1])]
		else:
			graph[int(i[0])].append(int(i[1]))
	for i in range(0,875715):
		if i not in graph:
			graph[i] = []
def bfs(graph,start):
	parents = {}
	levels[start] = 0
	parents[start] = None
	l = [start]
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
			l = l+next
			cur = next
			next = []
			count+=1
	return l
	

def connected_components(graph):
	l = []
	for i in range(1,875715):
		if i not in levels:
			l.append(bfs(graph,(i)))
	return l
			
create_graph(graph)
print graph.keys()[0:10]
print len(connected_components(graph))
