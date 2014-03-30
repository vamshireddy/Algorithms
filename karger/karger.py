import random
#create an empty graph
graph = {}
#Create a node list having the names of the nodes, it gets updates as the
# nodes are deleted
node_list = []

#reading the graph
def create_graph(graph):
	f = open("/home/vamshi/min.txt","r")
	l = f.readlines()
	for i in l:
		temp = i.split("\t")
		temp.remove("\r\n")
		graph[temp[0]] = temp[1:]
		node_list.append(temp[0])

#defining the min cut function
def min_cut(graph):
	length = len(graph)
	while length>2:
		# choose any random node in the graph
		r1 = random.choice(node_list)
		l = graph[r1]
		#if node's adj list length is zero, just discard it!
		if len(l)==0:
			graph.pop(r1)
			continue
		# choose another vertex, (here it is starting of the list) to form an edge
		ele = graph[r1][0]
		# if both are same then dicard
		if ele==r1:
			continue
		# if the pair is (u,v)
		# the, go to every node adj to v and go to that v's adj listnode's adj list
		# and find v and change it to u
		# continue for every node adj to v
		# finally go to u's adj list and add v's adj list nodes
		# also remove looping vertices in u's list
		# Remove ele from the graph
		for i in graph[ele]:
			if len(graph[i])==0:
				continue
			temp = graph[i]
			for j in range(len(temp)):
				if temp[j] == ele:
					temp[j] = r1
		graph[r1] = graph[r1]+graph[ele]
		i = 0
		while i!=-1:
			try:
				i = graph[r1].remove(r1)
			except ValueError:
				break
		graph.pop(ele)
		node_list.remove(ele)
		print node_list
		length-=1
	return len(graph[graph.keys()[0]])
create_graph(graph)
# we need to do this repeatedly for some number of times to get the min cut
# this algorithm is randomised, So it may return diffent answers, But we want minimum
print min_cut(graph)
	
