import java.util.ArrayList;

public class CengHashTable {

	private Integer hashPrefixLength;
	private Integer hashRowSize;
	private ArrayList<CengHashRow> hashRows = new ArrayList<CengHashRow>();
	private Integer bucketSize;
	private Integer maxPrefix;


	public CengHashTable()
	{
		// TODO: Create a hash table with only 1 row.
		hashPrefixLength = 0;
		hashRows.add(new CengHashRow("", 0, 0));
		hashRowSize = 1;
		bucketSize = CengPokeKeeper.getBucketSize();
		maxPrefix = (int) (Math.log(CengPokeKeeper.getHashMod()) / Math.log(2)) ;
	}

	public void deletePoke(Integer pokeKey)
	{
		// TODO: Empty Implementation
		ArrayList<CengBucket> bucketList = CengPokeKeeper.getBucketList().bucketList;

		int hashValue = (int) pokeKey % CengPokeKeeper.getHashMod();
		String s = Integer.toBinaryString(hashValue);
		String hashString = ("0".repeat(maxPrefix - s.length()) + s).substring(0, hashPrefixLength);

		Integer bucketIndex = getBucketIndex(hashString);

		int size = bucketList.get(bucketIndex).pokes.size();

		for (int i = 0; i < size; i++) {
			if (bucketList.get(bucketIndex).pokes.get(i).pokeKey() == pokeKey) {
				bucketList.get(bucketIndex).pokes.remove(i);
				break;
			}
		}

		Integer empty = 0;

		for (int i = 0; i < bucketList.size(); i++) {
			if (bucketList.get(i).pokes.size() == 0) {
				empty++;
			}
		}
		System.out.println("\"delete\": {");
		System.out.println("\t" + "\"emptyBucketNum\": " + empty);
		System.out.println("}");

	}

	public void addPoke(CengPoke poke)
	{			
		// TODO: Empty Implementation
		ArrayList<CengBucket> bucketList = CengPokeKeeper.getBucketList().bucketList;

		//hash values and useful strings
		int hashValue = (int) poke.pokeKey() % CengPokeKeeper.getHashMod();
		String s = Integer.toBinaryString(hashValue);
		String hashString = ("0".repeat(maxPrefix - s.length()) + s).substring(0, hashPrefixLength);

		Integer bucketIndex = getBucketIndex(hashString);

		if (bucketList.get(bucketIndex).pokes.size() == bucketSize) {
			//split the row if possible. If not double the hash table
			//and try adding again till you add the given poke.

			if (bucketList.get(bucketIndex).getHashPrefix() < hashPrefixLength) {
				// Rearrange the splitted rows and check if there is space
				// for the poke. If there is add it. If not add poke again.

				splitTheRow(hashString, poke, bucketIndex);
			} else {
				doubleHashTable();
				splitTheRow(hashString, poke, bucketIndex);
			}

		} else {
			bucketList.get(bucketIndex).pokes.add(poke);
		}

	}



	public void searchPoke(Integer pokeKey)
	{
		// TODO: Empty Implementation
		ArrayList<CengBucket> bucketList = CengPokeKeeper.getBucketList().bucketList;
		CengHashTable hashTable = CengPokeKeeper.getHashTable();

		int hashValue = (int) pokeKey % CengPokeKeeper.getHashMod();
		String s = Integer.toBinaryString(hashValue);
		String hashString = ("0".repeat(maxPrefix - s.length()) + s).substring(0, hashPrefixLength);



		Integer bucketIndex = getBucketIndex(hashString);
		Boolean exists = false;

		int currBSize = bucketList.get(bucketIndex).pokes.size();

		for (int i = 0; i < currBSize; i++) {
			if (bucketList.get(bucketIndex).pokes.get(i).pokeKey() == pokeKey) {
				exists = true;
			}
		}

		System.out.println("\"search\": {");

		if (exists) {
			Integer lD = bucketList.get(bucketIndex).getHashPrefix();

			String sForHashRows = hashString.substring(0, lD) + "0".repeat(hashPrefixLength - lD);

			Integer firstRowIndex = getFirstHashRow(sForHashRows);

			Integer rowCount = (int) Math.pow(2, (hashPrefixLength - lD));

			Integer size = 0;
			for (int i = 0; i < rowCount; i++) {
				//firstRowIndex + i

				System.out.println("\t" + "\"row\": {");
				System.out.println("\t".repeat(2) + "\"hashPref\": " + hashTable.hashRows.get(firstRowIndex + i).hashPrefix() + ",");
				System.out.println("\t".repeat(2) + "\"bucket\": {");
				System.out.println("\t".repeat(3) + "\"hashLength\": " + bucketList.get(hashTable.hashRows.get(firstRowIndex + i).getBucketIndex()).getHashPrefix() + ",");
				System.out.println("\t".repeat(3) + "\"pokes\": [");

				size = bucketList.get(hashRows.get(firstRowIndex + i).getBucketIndex()).pokes.size();
				for (int j = 0; j < size; j++) {
					CengPoke poke = bucketList.get(hashRows.get(firstRowIndex + i).getBucketIndex()).pokes.get(j);

					//ADDED
					s = Integer.toBinaryString((int) poke.pokeKey() % CengPokeKeeper.getHashMod());
					String hashStringFull = "0".repeat(maxPrefix - s.length()) + s;
					//ADDED

					System.out.println("\t".repeat(4) + "\"poke\": {");
					System.out.println("\t".repeat(5) + "\"hash\": " + hashStringFull + ",");
					System.out.println("\t".repeat(5) + "\"pokeKey\": " + poke.pokeKey() + ",");
					System.out.println("\t".repeat(5) + "\"pokeName\": " + poke.pokeName() + ",");
					System.out.println("\t".repeat(5) + "\"pokePower\": " + poke.pokePower() + ",");
					System.out.println("\t".repeat(5) + "\"pokeType\": " + poke.pokeType());

					if (j == size - 1) {
						System.out.println("\t".repeat(4) + "}");
					} else {
						System.out.println("\t".repeat(4) + "},");
					}
				}
				System.out.println("\t".repeat(3) + "]");
				System.out.println("\t".repeat(2) + "}");
				if (i == rowCount - 1) {
					System.out.println("\t".repeat(1) + "}");
				} else {
					System.out.println("\t".repeat(1) + "},");
				}

			}
		}
		System.out.println("}");

	}
	
	public void print()
	{
		CengHashTable hashTable = CengPokeKeeper.getHashTable();
		CengBucketList bucketList = CengPokeKeeper.getBucketList();

		Integer size;

		System.out.println("\"table\": {");
		for (int i = 0; i < hashRowSize; i++) {
			System.out.println("\t" + "\"row\": {");
			System.out.println("\t".repeat(2) + "\"hashPref\": " + hashTable.hashRows.get(i).hashPrefix() + ",");
			System.out.println("\t".repeat(2) + "\"bucket\": {");
			System.out.println("\t".repeat(3) + "\"hashLength\": " + bucketList.bucketList.get(hashTable.hashRows.get(i).getBucketIndex()).getHashPrefix() + ",");
			System.out.println("\t".repeat(3) + "\"pokes\": [");

			size = bucketList.bucketList.get(hashRows.get(i).getBucketIndex()).pokes.size();
			for (int j = 0; j < size; j++) {
				CengPoke poke = bucketList.bucketList.get(hashRows.get(i).getBucketIndex()).pokes.get(j);

				int hashValue = (int) poke.pokeKey() % CengPokeKeeper.getHashMod();
				String s = Integer.toBinaryString(hashValue);
				String hashString = "0".repeat(maxPrefix - s.length()) + s;


				System.out.println("\t".repeat(4) + "\"poke\": {");
				System.out.println("\t".repeat(5) + "\"hash\": " + hashString + ",");
				System.out.println("\t".repeat(5) + "\"pokeKey\": " + poke.pokeKey() + ",");
				System.out.println("\t".repeat(5) + "\"pokeName\": " + poke.pokeName() + ",");
				System.out.println("\t".repeat(5) + "\"pokePower\": " + poke.pokePower() + ",");
				System.out.println("\t".repeat(5) + "\"pokeType\": " + poke.pokeType());

				if (j == size - 1) {
					System.out.println("\t".repeat(4) + "}");
				} else {
					System.out.println("\t".repeat(4) + "},");
				}
			}
			System.out.println("\t".repeat(3) + "]");
			System.out.println("\t".repeat(2) + "}");
			if (i == hashRowSize - 1) {
				System.out.println("\t".repeat(1) + "}");
			} else {
				System.out.println("\t".repeat(1) + "},");
			}

		}
		System.out.println("}");

	}

	// GUI-Based Methods
	// These methods are required by GUI to work properly.
	
	public int prefixBitCount()
	{
		// TODO: Return table's hash prefix length.
		return hashPrefixLength;
	}
	
	public int rowCount()
	{
		// TODO: Return the count of HashRows in table.
		return hashRowSize;
	}
	
	public CengHashRow rowAtIndex(int index)
	{
		// TODO: Return corresponding hashRow at index.
		return hashRows.get(index);
	}
	
	// Own Methods
	private void splitTheRow(String s, CengPoke poke, Integer bucketIndex) {

		ArrayList<CengBucket> bucketList = CengPokeKeeper.getBucketList().bucketList;
		bucketList.add(new CengBucket());

		Integer a = 0;

		Integer len = s.length();
		Integer localD;

		Integer SsplitCount = (int) Math.pow(2, hashPrefixLength - bucketList.get(bucketIndex).getHashPrefix());
		Integer splitCount = (SsplitCount) / 2;

		for (int i = 0; i < hashRowSize; i++) {

			if (hashRows.get(i).hashPrefix().substring(0, len).equals(s)) {

				localD = bucketList.get(bucketIndex).getHashPrefix();
				for (int j = 0; j < splitCount; j++) {

					hashRows.get(i + j).setLocalDepth(localD + 1);
					hashRows.get(i + j).setBucketIndex(bucketList.size() - 1);

					bucketList.get(hashRows.get(i + j).getBucketIndex()).setLocalDepth(hashRows.get(i + j).getLocalDepth());
				}
				break;
			}

		}

		CengBucket temp = new CengBucket();
		for (int i = 0; i < bucketSize; i++) {
			temp.pokes.add(bucketList.get(bucketIndex).pokes.get(i));
		}
		bucketList.get(bucketIndex).pokes.clear();
		for (int i = 0; i < bucketSize; i++) {
			addPoke(temp.pokes.get(i));
		}

		addPoke(poke);

	}

	private void doubleHashTable() {
		String hP;
		CengHashRow before;


		for (int i = 0; i < hashRowSize*2; i+=2) {
			hP = hashRows.get(i).hashPrefix();
			before = hashRows.get(i);
			hashRows.add(i+1, new CengHashRow(before.hashPrefix() + "1", before.getBucketIndex(), before.getLocalDepth()));

			hashRows.get(i).setHashPrefix(hashRows.get(i).hashPrefix() + "0");
		}
		hashRowSize *= 2;
		hashPrefixLength++;

	}

	public Integer getBucketIndex(String s) {

		CengHashTable hashTable = CengPokeKeeper.getHashTable();
		Integer len = s.length();
		if (len == 0) {
			return 0;
		}
		return hashTable.hashRows.get(Integer.parseInt(s.substring(0, hashPrefixLength) , 2)).getBucketIndex();

	}

	public Integer getFirstHashRow(String s) {
		CengHashTable hashTable = CengPokeKeeper.getHashTable();
		Integer len = s.length();
		if (len == 0) {
			return 0;
		}
		return Integer.parseInt(s.substring(0, hashPrefixLength) , 2);
	}

}
