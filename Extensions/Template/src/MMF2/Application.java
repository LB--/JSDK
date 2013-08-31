package MMF2;

/**
 * Represents the "CRunApp" class.
 * <br/><b>Do not store instances of this class outside of the method it is given in.</b>
 * <br/><b>Runtime only.</b>
 */
public class Application
{
	/**
	 * Returns the "new" flags for the application.
	 * @return The "new" flags for the application.
	 */
	public native int NFlags();
	/**
	 * Returns the "original" flags for the application.
	 * @return The "original" flags for the application.
	 */
	public native int OFlags();

	/**
	 * Returns the number of frames in the application.
	 * @return The number of frames in the application.
	 */
	public native int NFrames();

	/**
	 * Returns the frame rate of the application.
	 * @return The frame rate of the application.
	 */
	public native int Framerate();

	/**
	 * Returns the name of the application.
	 * @return The name of the application.
	 */
	public native String AppName();
	/**
	 * Returns the file name of the application.
	 * @return The file name of the application.
	 */
	public native String AppFileName();
	/**
	 * Returns the application copyright.
	 * @return The application copyright.
	 */
	public native String Copyright();
	/**
	 * Returns the text displayed in the application's about box.
	 * @return The text displayed in the application's about box.
	 */
	public native String AboutText();
	/**
	 * Returns the file name of the help file.
	 * @return The file name of the help file.
	 */
	public native String HelpFile();

	/**
	 * Returns the number of extensions used by the application.
	 * @return The number of extensions used by the application.
	 */
	public native int NExtensions();
	/**
	 * Returns the number of movement extensions used by the application.
	 * @return The number of movement extensions used by the application.
	 */
	public native int NMovements();

	/**
	 * Returns the number of unique objects in the application.
	 * @return The number of unique objects in the application.
	 */
	public native int NObjects();

	/**
	 * Returns the parent application if this application is a sub-application.
	 * @return The parent application if this application is a sub-application, or null otherwise.
	 */
	public native Application Parent();

	/**
	 * Returns the index of the current frame.
	 * @return The index of the current frame.
	 */
	public native int CurrentFrameIndex();
	/**
	 * Returns the current frame.
	 * @return The current frame.
	 */
	public native Frame CurrentFrame();

	/**
	 * Returns the list of global values. All <code>Number</code>s in the list are either an instance of <code>Integer</code> or an instance of <code>Double</code>.
	 * @return The list of global values.
	 */
	public native Number[] GlobalValues();
	/**
	 * Returns the list of global strings.
	 * @return The list of global strings.
	 */
	public native String[] GlobalStrings();

	/**
	 * Represents the "CRunFrame" class.
	 * <br/><b>Do not store instances of this class outside of the method it is given in.</b>
	 */
	public class Frame
	{
		/**
		 * Returns the width of the frame in pixels.
		 * @return The width of the frame in pixels.
		 */
		public native int Width();
		/**
		 * Returns the height of the frame in pixels.
		 * @return The height of the frame in pixels.
		 */
		public native int Height();

		/**
		 * Returns the 24-bit color of the background of the frame.
		 * @return The 24-bit color of the background of the frame.
		 */
		public native int BackgroundColor();

		/**
		 * Returns the flags for the frame.
		 * @return The flags for the frame.
		 */
		public native int Flags();

		/**
		 * Returns the name of the frame.
		 * @return The name of the frame.
		 */
		public native String Name();

		/**
		 * Returns the number of objects in the frame.
		 * @return The number of objects in the frame.
		 */
		public native int NObjects();

		/**
		 * Returns the <code>Runtime</code> instance.
		 * @return The <code>Runtime</code> instance.
		 */
		public native Runtime GetRuntime();

		/**
		 * Represents the "LO" class.
		 * <br/><b>Do not store instances of this class outside of the method it is given in.</b>
		 */
		public class Obj
		{
			/**
			 * Returns the X coordinate of the object on the frame.
			 * @return The X coordinate of the object on the frame.
			 */
			public native int X();
			/**
			 * Returns the Y coordinate of the object on the frame.
			 * @return The Y coordinate of the object on the frame.
			 */
			public native int Y();
			/**
			 * Returns the Layer index of the object on the frame.
			 * @return The Layer index of the object on the frame.
			 */
			public native int Layer();

			/**
			 * Returns the object's type.
			 * @return The object's type.
			 */
			public native int Type();

			/**
			 * Represents the "OI" class.
			 * <br/><b>Do not store instances of this class outside of the method it is given in.</b>
			 */
			public class Info
			{
				/**
				 * Returns the object's type.
				 * @return the object's type.
				 */
				public native int Type();

				/**
				 * Returns the ink effect on the object.
				 * @return The ink effect on the object.
				 */
				public native int InkEffect();
				/**
				 * Returns the parameter for the ink effect on the object.
				 * @return the parameter for the ink effect on the object.
				 */
				public native int InkEffectParam();

				/**
				 * Returns the name of the object.
				 * @return the name of the object.
				 */
				public native String Name();

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
			private Obj(int donotcall)
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
		private Frame(int donotcall)
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
	private Application(int donotcall)
	{
		donotchange = donotcall;
	}
}