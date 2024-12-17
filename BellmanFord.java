import java.util.Scanner;

public class BellmanFord {
	private int distances[];
	private int numberofvertices;
	public static final int MAX_VALUE = 999;

	public BellmanFord(int numberofvertices) {
		this.numberofvertices = numberofvertices;
		distances = new int[numberofvertices + 1];
	}

	public void BellmanFordEvaluation(int source, int destination, int adjacencymatrix[][]) {
		for (int node = 1; node <= numberofvertices; node++) {
			distances[node] = MAX_VALUE;
		}
		distances[source] = 0;

		for (int node = 1; node <= numberofvertices - 1; node++) {
			for (int sourcenode = 1; sourcenode <= numberofvertices; sourcenode++) {
				for (int destinationnode = 1; destinationnode <= numberofvertices; destinationnode++) {
					if (adjacencymatrix[sourcenode][destinationnode] != MAX_VALUE) {
						if (distances[destinationnode] > distances[sourcenode] + adjacencymatrix[sourcenode][destinationnode]) {
							distances[destinationnode] = distances[sourcenode] + adjacencymatrix[sourcenode][destinationnode];
						}
					}
				}
			}
		}

		for (int sourcenode = 1; sourcenode <= numberofvertices; sourcenode++) {
			for (int destinationnode = 1; destinationnode <= numberofvertices; destinationnode++) {
				if (adjacencymatrix[sourcenode][destinationnode] != MAX_VALUE) {
					if (distances[destinationnode] > distances[sourcenode] + adjacencymatrix[sourcenode][destinationnode]) {
						System.out.println("The Graph contains negative edge cycle");
					}
				}
			}
		}

		for (int vertex = 1; vertex <= numberofvertices; vertex++) {
			if (vertex == destination) {
				System.out.println("\nDistance Of Source " + source + " To Destination " + vertex + " Is " + distances[vertex]);
			}
		}
	}

	public static void main(String... arg) {
		int numberofvertices = 0;
		int source, destination;
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter The Number Of Vertices: ");
		numberofvertices = scanner.nextInt();

		int adjacencymatrix[][] = new int[numberofvertices + 1][numberofvertices + 1];

		System.out.println("Enter The Adjacency Matrix: ");
		for (int sourcenode = 1; sourcenode <= numberofvertices; sourcenode++) {
			for (int destinationnode = 1; destinationnode <= numberofvertices; destinationnode++) {
				adjacencymatrix[sourcenode][destinationnode] = scanner.nextInt();
				if (sourcenode == destinationnode) {
					adjacencymatrix[sourcenode][destinationnode] = 0;
					continue;
				}
				if (adjacencymatrix[sourcenode][destinationnode] == 0) {
					adjacencymatrix[sourcenode][destinationnode] = MAX_VALUE;
				}
			}
		}

		System.out.print("Enter the source vertex: ");
		source = scanner.nextInt();

		System.out.print("Enter the destination vertex: ");
		destination = scanner.nextInt();

		BellmanFord bellmanford = new BellmanFord(numberofvertices);
		bellmanford.BellmanFordEvaluation(source, destination, adjacencymatrix);

		scanner.close();
	}
}

/*
##Output
Enter The Number Of Vertices: 6
Enter The Adjacency Matrix:
0 6 4 5 999 999
999 0 999 999 -1 999
999 999 0 999 3 999
999 999 -2 0 999 -1
999 999 999 999 0 3
999 999 999 999 999 0
Enter the source vertex: 1
Enter the destination vertex: 6

Distance Of Source 1 To Destination 6 Is 4
*/
