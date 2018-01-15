package com.navyliu.test_1;

/**
 * Created by Administrator on 2017-12-20.
 */

public class JNIDynamicUtils {
	/**
	 * 调用C++代码的方法，返回对应的字符串
	 *
	 * @return
	 */
	public static native String getHelloStringFromJNI();

	/**
	 * 加载so库或者jni库
	 */
	static {
		System.loadLibrary("JNI_DYNAMIC_ANDROID_TEST");
	}
}
