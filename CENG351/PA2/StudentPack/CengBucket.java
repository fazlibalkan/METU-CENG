import java.util.ArrayList;
import java.util.List;

public class CengBucket {

	private Integer localDepth;
	public ArrayList<CengPoke> pokes = new ArrayList<CengPoke>();

	public CengBucket() {
		localDepth = 0;
	}

	// GUI-Based Methods
	// These methods are required by GUI to work properly.

	public int pokeCount()
	{
		// TODO: Return the pokemon count in the bucket.
		int pokeCount = pokes.size();
		return pokeCount;
	}

	public CengPoke pokeAtIndex(int index)
	{
		// TODO: Return the corresponding pokemon at the index.
		return pokes.get(index);
	}

	public int getHashPrefix()
	{
		// TODO: Return hash prefix length.
		return localDepth;
	}

	public Boolean isVisited()
	{
		// TODO: Return whether the bucket is found while searching.
		return false;
	}

	// Own Methods

	public void setHashPrefix() {

	}

	public void setLocalDepth(Integer ld) {
		localDepth = ld;
	}
}
