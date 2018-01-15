package com.navyliu.test_1;

/**
 * Created by Administrator on 2017-12-22.
 */

public class JNIDynamicExceptionUtils {
	/**
	 * 调用C++代码的方法，当字符串为null或长度为5的时候抛出异常，否则，返回字符串长度
	 * @param str
	 * @return
	 * @throws NullPointerException
	 * @throws IllegalArgumentException
	 */
	public static native int getStrLength(String str) throws NullPointerException, IllegalArgumentException;

	/**
	 * 加载so库或者jni库
	 */
	static {
		System.loadLibrary("JNI_DYNAMIC_EXCEPTION_ANDROID_TEST");
	}
}
