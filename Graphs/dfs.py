parents = {}
list = []
graph = {}
def create_DAG(graph):
	graph['a'] = ['b','g']
	graph['b'] = ['c']	
	graph['c'] = ['d','f']
	graph['d'] = ['e','f']
	graph['e'] = []
	graph['f'] = []
	graph['g'] = ['c']
	graph['h'] = ['g','f']
	
	
	

def create_graph(graph):
	f = open("/home/vamshi/min.txt","r")
	l = f.readlines()
	for i in l:
		temp = i.split("\t")
		temp.remove("\r\n")
		graph[temp[0]] = temp[1:]
		
def dfs_visit(v):
	for i in graph[v]:
		if i not in parents:
			parents[i] = v
			dfs_visit(i)
	list.append(v)


def dfs(graph):
	for i in graph.keys():
		if i not in parents:
			parents[i] = None
			dfs_visit(i)
create_DAG(graph)
dfs(graph)
list.reverse()
print list
