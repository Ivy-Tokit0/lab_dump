import java.io.InputStreamReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.io.File;
import java.io.FileInputStream;
import java.net.ServerSocket;
import java.util.Scanner;

class Server {
	public static void main(String args[]) throws Exception {
		String filename;
		System.out.print("Enter Filename: ");
		Scanner sc = new Scanner(System.in);
		filename = sc.nextLine();
		sc.close();

		while (true) {
			ServerSocket ss = new ServerSocket(5000);
			System.out.println("Wait for request");
			Socket s = ss.accept();
			System.out.println("Connected with " + s.getInetAddress().toString());

			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());

			try {
				String str = "";
				str = din.readUTF();
				System.out.println("Send get token");
				if (!str.equals("stop")) {
					System.out.println("Sending file: " + filename);
					dout.writeUTF(filename);
					dout.flush();

					File f = new File(filename);
					FileInputStream fin = new FileInputStream(f);
					long sz = (int) f.length();
					byte b[] = new byte[1024];
					int read;

					dout.writeUTF(Long.toString(sz));
					dout.flush();
					System.out.println("Size: " + sz);
					System.out.println("Buffer size: " + ss.getReceiveBufferSize());

					while ((read = fin.read(b)) != -1) {
						dout.write(b, 0, read);
						dout.flush();
					}
					fin.close();
					System.out.println("OK");
					dout.flush();
				}
				dout.writeUTF("stop");
				System.out.println("Send complete");
				dout.flush();
			} catch (Exception e) {
				e.printStackTrace();
				System.out.println("Error occurred");
			}
			din.close();
			s.close();
			ss.close();
		}
	}
}

/*
##Output Terminal 1
Enter Filename: text.txt
*/
