package com.navyliu.test_1;

/**
 * Created by Administrator on 2017-12-22.
 */

public class JNIDynamicPictureGrayUtils {
	/**
	 * 调用C++方法，灰化图片
	 * @param buf
	 * @param w
	 * @param h
	 * @return
	 */
	public static native int[] grayPicture(int[] buf, int w, int h);

	/**
	 * 加载so库或jni库
	 */
	static {
		System.loadLibrary("JNI_DYNAMIC_PICTURE_GRAY_ANDROID_TEST");
	}
}
