package com.navyliu.test_1;

/**
 * Created by Administrator on 2017-12-20.
 */

public class JNIDynamicSumUtils {
	/**
	 * 调用C++代码的方法，返回对应的字符串
	 *
	 * @return
	 */
	public static native String getSumFromJNI(int i1, int i2);

	/**
	 * 加载so库或者jni库
	 */
	static {
		System.loadLibrary("JNI_DYNAMIC_SUM_ANDROID_TEST");
	}
}
