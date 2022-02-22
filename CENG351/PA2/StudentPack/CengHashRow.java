import java.util.ArrayList;

public class CengHashRow {

	private String hashPrefix;
	private Integer bucketIndex;
	private Integer localDepth;

	CengHashRow(String hP, Integer bI, Integer ld){
		hashPrefix = hP;
		bucketIndex = bI;
		localDepth = ld;
	}

	// GUI-Based Methods
	// These methods are required by GUI to work properly.
	
	public String hashPrefix()
	{
		// TODO: Return row's hash prefix (such as 0, 01, 010, ...)
		return hashPrefix;
	}
	
	public CengBucket getBucket()
	{
		// TODO: Return the bucket that the row points at.
		return CengPokeKeeper.getBucketList().bucketList.get(bucketIndex);
	}
	
	public boolean isVisited()
	{
		// TODO: Return whether the row is used while searching.
		return false;		
	}



	// Own Methods
	public Integer getBucketIndex(){

		return bucketIndex;
	}

	public void setLocalDepth(Integer ld) {
		localDepth = ld;
		CengPokeKeeper.getBucketList().bucketList.get(bucketIndex).setLocalDepth(ld);
	}
	public Integer getLocalDepth() {
		return localDepth;
	}

	public void setBucketIndex(Integer bI) {
		bucketIndex = bI;
	}

	public void setHashPrefix(String s) {
		hashPrefix = s;
	}

	public void incrementHashPrefix() {
		hashPrefix =  "0" +  hashPrefix;
	}
}
