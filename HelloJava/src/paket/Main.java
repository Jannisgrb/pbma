package paket;

public class Main {

	public void doMain(String[] args) {
		System.out.println("Hello Java World");
		for (int i=0; i < args.length; ++i) {
			System.out.format("%2d: %s\n", i, args[i]);
		}
	}
	
	public static void main(String[] args) {
		new Main().doMain(args);
	}

}
