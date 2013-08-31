package MMF2;

/**
 * Represents the "mv" class.
 * <br/><b>Do not store instances of this class outside of the method it is given in.</b>
 */
public final class Funcs
{
	/**
	 * Returns the <code>Application</code> instance.
	 * <br/><b>Runtime only.</b>
	 * @return The <code>Application</code> instance.
	 */
	public native Application App();
	/**
	 * Returns the current <code>Application.Frame</code> instance.
	 * <br/><b>Runtime only.</b>
	 * @return The current <code>Application.Frame</code> instance.
	 */
	public native Application.Frame AppFrame();

	/**
	 * Returns the runtime preferences.
	 * <br/><b>Runtime only.</b>
	 * @return The runtime preferences.
	 */
	public native int Prefs();

	//ImageFilterManager
	//SoundFilterManager
	//SoundManager

	/**
	 * Returns the application path.
	 * @return The application path.
	 */
	public native String AppPath();

	/**
	 * Returns the version flags for MMF2.
	 * <br/><b>Edittime only.</b>
	 * @return The version flags for MMF2.
	 */
	public native int MMF2Version();

	/**
	 * Opens a help file and navigates it to a specific topic and help context.
	 * <br/><b>Edittime only.</b>
	 * @param HelpFile The filename of the help file.
	 * @param HelpContextID The help context.
	 * @param HelpURL The URL of the help topic.
	 */
	public native void OpenHelp(String HelpFile, int HelpContextID, String HelpURL);

	/**
	 * Triggers top-level conditions in your extension by ID.
	 * <br/><b>Runtime only.</b>
	 * @param RunExt Your extension's runtime class instance (just pass <code>this</code>).
	 * @param ID The ID of the condition to trigger.
	 */
	public native void TriggerCondition(Ext.Runtime RunExt, int ID);
	/**
	 * Asks MMF2 to re-handle your extension.
	 * <br/><b>Runtime only.</b>
	 */
	public native void Rehandle();
	/**
	 * Asks MMF2 to re-draw your object.
	 * <br/><b>Runtime only.</b>
	 */
	public native void Redraw();
	/**
	 * Asks MMF2 to reposition your object.
	 * <br/><b>Runtime only.</b>
	 * @param x The new X position.
	 * @param y The new Y position.
	 */
	public native void Position(int x, int y);

	/**
	 * The identifier for the C++ proxy.
	 * <br/><b>DO NOT CHANGE.</b>
	 */
	private int donotchange;
	/**
	 * The constructor for the C++ proxy.
	 * <br/><b>DO NOT CALL.</b>
	 * @param donotcall The identifier.
	 */
	private Funcs(int donotcall)
	{
		donotchange = donotcall;
	}
}