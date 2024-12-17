import java.net.*;

class Datagram {
	public static int serverPort = 3060;
	public static int clientPort = 3080;
	public static int buffer_size = 1024;
	public static DatagramSocket ds;
	public static byte buffer[] = new byte[buffer_size];

	public static void TheServer() throws Exception {
		int pos = 0;
		while (true) {
			int c = System.in.read();
			switch (c) {
				case -1:
					System.out.println("Server Quits.");
					return;
				case '\r':
					break;
				case '\n':
					ds.send(new DatagramPacket(buffer, pos, InetAddress.getLocalHost(), clientPort));
					pos = 0;
					break;
				default:
					buffer[pos++] = (byte) c;
			}
		}
	}

	public static void TheClient() throws Exception {
		while (true) {
			DatagramPacket p = new DatagramPacket(buffer, buffer.length);
			ds.receive(p);
			System.out.println(new String(p.getData(), 0, p.getLength()));
		}
	}

	public static void main(String args[]) throws Exception {
		if (args[0].equals("server")) {
			ds = new DatagramSocket(serverPort);
			System.out.println("Starting Server...");
			TheServer();
		} else if (args[0].equals("client")) {
			ds = new DatagramSocket(clientPort);
			System.out.println("Starting Client...");
			TheClient();
		}
	}
}

/*
##Output: Server
javac Datagram.java && java Datagram server
#Enter any Messages
#To Quit Press Ctrl+D on Unix/Linux/Mac | Ctrl+Z on Windows
*/

/*
##Output: Client
javac Datagram.java && java Datagram client
*/
