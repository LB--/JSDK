package JSDK;

import Services.CFontInfo;
import java.awt.*;
import java.awt.image.*;
import java.io.*;
import Extensions.*;
import Services.*;
import RunLoop.*;
import Expressions.*;
import Sprites.*;
import Conditions.*;
import Actions.*;
import Expressions.*;
import Objects.*;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;

/**
 * Mid-way class to handle the MMF2 Java SDK and other things.
 */
public abstract class Runtime extends CRunExtension
{
	public Runtime()
	{
		//
	}
	public static native int Version();
	private static Class Class()
	{
		return Ext.Runtime.class;
	}

	@Override public int getNumberOfConditions()
	{
		return 0;
	}
	@Override public boolean createRunObject(CBinaryFile file, CCreateObjectInfo cob, int version)
	{
		return true;
	}
	@Override public void destroyRunObject(boolean bFast)
	{
	}
	@Override public int handleRunObject()
	{
		return REFLAG_ONESHOT;
	}
	@Override public void displayRunObject(Graphics2D g2)
	{
	}
	@Override public void pauseRunObject()
	{
	}
	@Override public void continueRunObject()
	{
	}
	@Override public boolean saveRunObject(DataOutputStream stream)
	{
		return true;
	}
	@Override public boolean loadRunObject(DataInputStream stream)
	{
		return true;
	}
	@Override public void saveBackground(BufferedImage img)
	{
	}
	@Override public void restoreBackground(Graphics2D g)
	{
	}
	@Override public void killBackground()
	{
	}
	@Override public CFontInfo getRunObjectFont()
	{
		return null;
	}
	@Override public void setRunObjectFont(CFontInfo fi, CRect rc)
	{
	}
	@Override public int getRunObjectTextColor()
	{
		return 0;
	}
	@Override public void setRunObjectTextColor(int rgb)
	{
	}
	@Override public CMask getRunObjectCollisionMask(int flags)
	{
		return null;
	}
	@Override public BufferedImage getRunObjectSurface()
	{
		return null;
	}
	@Override public void getZoneInfos()
	{
	}

	@Override public boolean condition(int num, CCndExtension cnd)
	{
		return false;
	}
	@Override public void action(int num, CActExtension act)
	{
	}
	@Override public CValue expression(int num)
	{
		return null;
	}

	//*** Circular movement
	public static int SET_CIRCLE_CENTRE_X=3345;
	public static int SET_CIRCLE_CENTRE_Y=3346;
	public static int SET_CIRCLE_ANGSPEED=3347;
	public static int SET_CIRCLE_CURRENTANGLE=3348;
	public static int SET_CIRCLE_RADIUS=3349;
	public static int SET_CIRCLE_SPIRALVEL=3350;
	public static int SET_CIRCLE_MINRADIUS=3351;
	public static int SET_CIRCLE_MAXRADIUS=3352;
	public static int SET_CIRCLE_ONCOMPLETION=3353;
	public static int GET_CIRCLE_CENTRE_X=3354;
	public static int GET_CIRCLE_CENTRE_Y=3355;
	public static int GET_CIRCLE_ANGSPEED=3356;
	public static int GET_CIRCLE_CURRENTANGLE=3357;
	public static int GET_CIRCLE_RADIUS=3358;
	public static int GET_CIRCLE_SPIRALVEL=3359;
	public static int GET_CIRCLE_MINRADIUS=3360;
	public static int GET_CIRCLE_MAXRADIUS=3361;

	//*** Regular Polygon movement
	public static int SET_REGPOLY_CENTRE_X=3445;
	public static int SET_REGPOLY_CENTRE_Y=3446;
	public static int SET_REGPOLY_NUMSIDES=3447;
	public static int SET_REGPOLY_RADIUS=3448;
	public static int SET_REGPOLY_ROTATION_ANGLE=3449;
	public static int SET_REGPOLY_VELOCITY=3450;
	public static int GET_REGPOLY_CENTRE_X=3451;
	public static int GET_REGPOLY_CENTRE_Y=3452;
	public static int GET_REGPOLY_NUMSIDES=3453;
	public static int GET_REGPOLY_RADIUS=3454;
	public static int GET_REGPOLY_ROTATION_ANGLE=3455;
	public static int GET_REGPOLY_VELOCITY=3456;

	//*** Sinewave movement
	public static int SET_SINEWAVE_SPEED=3545;
	public static int SET_SINEWAVE_STARTX=3546;
	public static int SET_SINEWAVE_STARTY=3547;
	public static int SET_SINEWAVE_FINALX=3548;
	public static int SET_SINEWAVE_FINALY=3549;
	public static int SET_SINEWAVE_AMPLITUDE=3550;
	public static int SET_SINEWAVE_ANGVEL=3551;
	public static int SET_SINEWAVE_STARTANG=3552;
	public static int SET_SINEWAVE_CURRENTANGLE=3553;
	public static int GET_SINEWAVE_SPEED=3554;
	public static int GET_SINEWAVE_STARTX=3555;
	public static int GET_SINEWAVE_STARTY=3556;
	public static int GET_SINEWAVE_FINALX=3557;
	public static int GET_SINEWAVE_FINALY=3558;
	public static int GET_SINEWAVE_AMPLITUDE=3559;
	public static int GET_SINEWAVE_ANGVEL=3560;
	public static int GET_SINEWAVE_STARTANG=3561;
	public static int GET_SINEWAVE_CURRENTANGLE=3562;
	public static int RESET_SINEWAVE=3563;
	public static int SET_SINEWAVE_ONCOMPLETION=3564;

	//*** Simple Ellipse movement
	public static int SET_SIMPLEELLIPSE_CENTRE_X=3645;
	public static int SET_SIMPLEELLIPSE_CENTRE_Y=3646;
	public static int SET_SIMPLEELLIPSE_RADIUS_X=3647;
	public static int SET_SIMPLEELLIPSE_RADIUS_Y=3648;
	public static int SET_SIMPLEELLIPSE_ANGSPEED=3649;
	public static int SET_SIMPLEELLIPSE_CURRENTANGLE=3650;
	public static int SET_SIMPLEELLIPSE_OFFSETANGLE=3651;
	public static int GET_SIMPLEELLIPSE_CENTRE_X=3652;
	public static int GET_SIMPLEELLIPSE_CENTRE_Y=3653;
	public static int GET_SIMPLEELLIPSE_RADIUS_X=3654;
	public static int GET_SIMPLEELLIPSE_RADIUS_Y=3655;
	public static int GET_SIMPLEELLIPSE_ANGSPEED=3656;
	public static int GET_SIMPLEELLIPSE_CURRENTANGLE=3657;
	public static int GET_SIMPLEELLIPSE_OFFSETANGLE=3658;

	//*** Invaders movement
	public static int SET_INVADERS_SPEED=3745;
	public static int SET_INVADERS_STEPX=3746;
	public static int SET_INVADERS_STEPY=3747;
	public static int SET_INVADERS_LEFTBORDER=3748;
	public static int SET_INVADERS_RIGHTBORDER=3749;
	public static int GET_INVADERS_SPEED=3750;
	public static int GET_INVADERS_STEPX=3751;
	public static int GET_INVADERS_STEPY=3752;
	public static int GET_INVADERS_LEFTBORDER=3753;
	public static int GET_INVADERS_RIGHTBORDER=3754;

	//*** Vector movement
	public static int SET_Projectile_X=3845;
	public static int SET_Projectile_Y=3846;
	public static int SET_Projectile_XY=3847;
	public static int SET_Projectile_AddDistX=3848;
	public static int SET_Projectile_AddDistY=3849;
	public static int SET_Projectile_Dir=3850;
	public static int SET_Projectile_RotateTowardsAngle=3851;
	public static int SET_Projectile_RotateTowardsPoint=3852;
	public static int SET_Projectile_RotateTowardsObject=3853;
	public static int SET_Projectile_Speed=3854;
	public static int SET_Projectile_SpeedX=3855;
	public static int SET_Projectile_SpeedY=3856;
	public static int SET_Projectile_AddSpeedX=3857;
	public static int SET_Projectile_AddSpeedY=3858;
	public static int SET_Projectile_MinSpeed=3859;
	public static int SET_Projectile_MaxSpeed=3860;
	public static int SET_Projectile_Gravity=3861;
	public static int SET_Projectile_GravityDir=3862;
	public static int SET_Projectile_BounceCoeff=3863;
	public static int SET_Projectile_ForceBounce=3864;

	public static int GET_Projectile_X=3865;
	public static int GET_Projectile_Y=3866;
	public static int GET_Projectile_Dir=3867;
	public static int GET_Projectile_Speed=3868;
	public static int GET_Projectile_SpeedX=3869;
	public static int GET_Projectile_SpeedY=3870;
	public static int GET_Projectile_MinSpeed=3871;
	public static int GET_Projectile_MaxSpeed=3871;
	public static int GET_Projectile_Gravity=3872;
	public static int GET_Projectile_GravityDir=3873;
	public static int GET_Projectile_BounceCoef=3874;

	//*** Presentation movement
	public static int SET_PRESENTATION_Next=3945;
	public static int SET_PRESENTATION_Prev=3946;
	public static int SET_PRESENTATION_ToStart=3947;
	public static int SET_PRESENTATION_ToEnd=3948;
	public static int GET_PRESENTATION_Index=3949;
	public static int GET_PRESENTATION_LastIndex=3950;

	public static int SPACE_SETPOWER=0;
	public static int SPACE_SETSPEED=1;
	public static int SPACE_SETDIR=2;
	public static int SPACE_SETDEC=3;
	public static int SPACE_SETROTSPEED=4;
	public static int SPACE_SETGRAVITY=5;
	public static int SPACE_SETGRAVITYDIR=6;
	public static int SPACE_APPLYREACTOR=7;
	public static int SPACE_APPLYROTATERIGHT=8;
	public static int SPACE_APPLYROTATELEFT=9;
	public static int SPACE_GETGRAVITY=10;
	public static int SPACE_GETGRAVITYDIR=11;
	public static int SPACE_GETDECELERATION=12;
	public static int SPACE_GETROTATIONSPEED=13;
	public static int SPACE_GETTHRUSTPOWER=14;
}