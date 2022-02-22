import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Scanner;

public class CengPokeParser {

	public static ArrayList<CengPoke> parsePokeFile(String filename)
	{
		ArrayList<CengPoke> pokeList = new ArrayList<CengPoke>();

		// You need to parse the input file in order to use GUI tables.
		// TODO: Parse the input file, and convert them into CengPokes

		try {
			String strCurrentLine;
			String[] splitted;

			BufferedReader br = new BufferedReader(new FileReader("./pokemons.txt"));

			while ((strCurrentLine = br.readLine()) != null) {
				splitted = strCurrentLine.split("\\s+");
				pokeList.add(Integer.parseInt(splitted[1]), new CengPoke(Integer.parseInt(splitted[1]), splitted[2], splitted[3], splitted[4]));
			}

		} catch (IOException e) {

			e.printStackTrace();

		}

		return pokeList;
	}
	
	public static void startParsingCommandLine() throws IOException
	{
		// TODO: Start listening and parsing command line -System.in-.
		// There are 5 commands:
		// 1) quit : End the app. Print nothing, call nothing.
		// 2) add : Parse and create the poke, and call CengPokeKeeper.addPoke(newlyCreatedPoke).
		// 3) search : Parse the pokeKey, and call CengPokeKeeper.searchPoke(parsedKey).
		// 4) delete: Parse the pokeKey, and call CengPokeKeeper.removePoke(parsedKey).
		// 5) print : Print the whole hash table with the corresponding buckets, call CengPokeKeeper.printEverything().

		// Commands (quit, add, search, print) are case-insensitive.
		CengHashTable hashTable = CengPokeKeeper.getHashTable();
		CengBucketList bucketList = CengPokeKeeper.getBucketList();

		String[] words;
		Scanner scanner = new Scanner(System.in);
		Boolean quit = false;
		while (!quit) {
			String s = scanner.nextLine();
			if (s.toLowerCase().equals("quit")) {
				quit = true;
				break;
			}

			words = s.split("\\t");

			if (words[0].toLowerCase().equals("add")) {
				CengPoke poke = new CengPoke(Integer.parseInt(words[1]), words[2], words[3], words[4]);
				hashTable.addPoke(poke);
			} else if (words[0].toLowerCase().equals("search")) {
				hashTable.searchPoke(Integer.parseInt(words[1]));
			} else if (words[0].toLowerCase().equals("delete")) {
				hashTable.deletePoke(Integer.parseInt(words[1]));
			} else if (words[0].toLowerCase().equals("print")) {
				hashTable.print();
			}

		}

		scanner.close();

	}
}
