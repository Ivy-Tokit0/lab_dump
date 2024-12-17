import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;

public class Client {

	public static void main(String[] args) throws Exception {
		String address = "";
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter Server Address: ");
		address = scanner.nextLine();

		try (Socket socket = new Socket(address, 5000)) {
			DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
			DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
			BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

			System.out.println("Send 'get' To Start");
			String input = bufferedReader.readLine();

			while (!input.equals("get")) {
				input = bufferedReader.readLine();
			}

			dataOutputStream.writeUTF(input);
			dataOutputStream.flush();

			String filename = dataInputStream.readUTF();
			System.out.println("Receiving File: " + filename);
			filename = "client" + filename;
			System.out.println("Saving as File " + filename);

			long fileSize = Long.parseLong(dataInputStream.readUTF());
			System.out.println("File Size: " + (fileSize / (1024)) + " KB");

			byte[] buffer = new byte[1024];
			System.out.println("Receiving File");

			try (FileOutputStream fileOutputStream = new FileOutputStream(new File(filename), true)) {
				long bytesRead;
				do {
					bytesRead = dataInputStream.read(buffer, 0, buffer.length);
					fileOutputStream.write(buffer, 0, (int) bytesRead);
				} while (bytesRead >= 1024);
			}

			System.out.println("Completed");
		} catch (Exception e) {
			System.out.println("An error occurred: " + e.getMessage());
		}
	}
}

/*
##Output Terminal 2
Enter Server Address: localhost
Send 'get' To Start
get //Enter get, You Will Recive a File
*/
