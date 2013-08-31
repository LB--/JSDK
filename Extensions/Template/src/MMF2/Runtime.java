package MMF2;

/**
 * Represents the "RunHeader" class.
 * <br/><b>Do not store instances of this class outside of the method it is given in.</b>
 */
public class Runtime
{
	/**
	 * Returns the number of loops since the start of the frame.
	 * @return The number of loops since the start of the frame.
	 */
	public native int NLoops();
	/**
	 * Returns the millisecond timer.
	 * @return the millisecond timer.
	 */
	public native int Timer();

	/**
	 * Represents the "headerObject" class.
	 * <br/><b>Do not store instances of this class outside of the method it is given in.</b>
	 */
	public class Info
	{
		/**
		 * Returns the number for your object.
		 * @return The number for your object.
		 */
		public native short ObjectNumber();

		/**
		 * Returns the <code>Runtime</code> instance.
		 * @return the <code>Runtime</code> instance.
		 */
		public native Runtime GetRuntime();

		/**
		 * Returns the X position of your object.
		 * @return the X position of your object.
		 */
		public native int X();
		/**
		 * Returns the Y position of your object.
		 * @return the Y position of your object.
		 */
		public native int Y();

		/**
		 * Returns the X coordinate of your object's hot spot.
		 * @return The X coordinate of your object's hot spot.
		 */
		public native int XHS();
		/**
		 * Returns the Y coordinate of your object's hot spot.
		 * @return The Y coordinate of your object's hot spot.
		 */
		public native int YHS();

		/**
		 * Returns the width of your object.
		 * @return The width of your object.
		 */
		public native int Width();
		/**
		 * Returns the height of your object.
		 * @return The height of your object.
		 */
		public native int Height();

		/**
		 * Returns the flags for your object.
		 * @return The flags for your object.
		 */
		public native int Flags();

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
		private Info(int donotcall)
		{
			donotchange = donotcall;
		}
	}

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
	private Runtime(int donotcall)
	{
		donotchange = donotcall;
	}
}