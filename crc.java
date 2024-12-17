import java.io.*;

class crc {
	public static void main(String a[]) throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);

		int[] message;
		int[] gen;
		int[] app_message;
		int[] rem;
		int[] trans_message;
		int message_bits, gen_bits, total_bits;

		System.out.print("Enter number of bits in message: ");
		message_bits = Integer.parseInt(br.readLine());
		message = new int[message_bits];

		System.out.println("Enter message bits[]: ");
		for (int i = 0; i < message_bits; i++) {
			message[i] = Integer.parseInt(br.readLine());
		}

		System.out.print("\nEnter number of bits in gen: ");
		gen_bits = Integer.parseInt(br.readLine());
		gen = new int[gen_bits];

		System.out.println("Enter gen bits[]: ");
		for (int i = 0; i < gen_bits; i++) {
			gen[i] = Integer.parseInt(br.readLine());
		}

		total_bits = message_bits + gen_bits - 1;
		app_message = new int[total_bits];
		rem = new int[total_bits];
		trans_message = new int[total_bits];

		for (int i = 0; i < message.length; i++) {
			app_message[i] = message[i];
		}

		System.out.print("\nMessage bits: ");
		for (int i = 0; i < message_bits; i++) {
			System.out.print(message[i]);
		}

		System.out.print("\nGenerators bits: ");
		for (int i = 0; i < gen_bits; i++) {
			System.out.print(gen[i]);
		}

		System.out.print("\nAppended message: ");
		for (int i = 0; i < app_message.length; i++) {
			System.out.print(app_message[i]);
		}

		for (int j = 0; j < app_message.length; j++) {
			rem[j] = app_message[j];
		}

		rem = computecrc(app_message, gen, rem);

		for (int i = 0; i < app_message.length; i++) {
			trans_message[i] = (app_message[i] ^ rem[i]);
		}

		System.out.print("\nTransmitted message from the transmitter is: ");
		for (int i = 0; i < trans_message.length; i++) {
			System.out.print(trans_message[i]);
		}

		System.out.println("\n\nEnter received message of " + total_bits + " bits at receiver end[]: ");
		for (int i = 0; i < trans_message.length; i++) {
			trans_message[i] = Integer.parseInt(br.readLine());
		}

		System.out.print("\nReceived message: ");
		for (int i = 0; i < trans_message.length; i++) {
			System.out.print(trans_message[i]);
		}

		for (int j = 0; j < trans_message.length; j++) {
			rem[j] = trans_message[j];
		}

		rem = computecrc(trans_message, gen, rem);

		for (int i = 0; i < rem.length; i++) {
			if (rem[i] != 0) {
				System.out.println("\nThere Is Error In The Received Message!!!");
				break;
			}
			if (i == rem.length - 1) {
				System.out.println("\nThere Is No Error In The Received Message!!!");
			}
		}
	}

	static int[] computecrc(int app_message[], int gen[], int rem[]) {
		int current = 0;
		while (true) {
			for (int i = 0; i < gen.length; i++) {
				rem[current + i] = (rem[current + i] ^ gen[i]);
			}
			while (rem[current] == 0 && current != rem.length - 1) {
				current++;
			}
			if ((rem.length - current) < gen.length) {
				break;
			}
		}
		return rem;
	}
}
