shortest_paths = {}
graph = {}
NO_OF_VERTICES = 200
MAX_VALUE = 1000000000000


def create_graph(graph):
	ifile = open("/home/vamshi/Desktop/dijkstraData.txt","r")
	l = ifile.readlines()
	for i in l:
		temp = i.split("\t")
		vertex = int(temp[0])
		graph[vertex] = []
		for i in temp[1:-1]:
			p = i.split(",")
			t = []
			for i in p:
				t.append(int(i))
			graph[vertex].append(t)

def dijkstra(graph,sp,start):
	visited = []
	visited.append(start)
	sp[start] = 0
	count = 1
	while count != NO_OF_VERTICES:
		minimum = MAX_VALUE
		min_vertex = None
		for i in sp.keys():
			for j in graph[i]:
				if j[0] not in visited:
					if sp[i]+j[1]<minimum:
						min_vertex = j[0]
						minimum = sp[i]+j[1]
		sp[min_vertex] = minimum
		visited.append(min_vertex)
		count += 1
		
		
create_graph(graph)
dijkstra(graph,shortest_paths,1)
l = [7,37,59,82,99,115,133,165,188,197]
for i in l:
	print shortest_paths[i]
	
