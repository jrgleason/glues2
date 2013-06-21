LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := glues
LOCAL_C_INCLUDES := $(LOCAL_PATH)/..
# LOCAL_CFLAGS := -O3 -ffast-math
LOCAL_SRC_FILES := \
	$(subst $(LOCAL_PATH)/,, \
	$(wildcard $(LOCAL_PATH)/*.c))
LOCAL_LDLIBS := -lm -llog -ldl -lGLESv2 
# -lGLESv1_CM
include $(BUILD_SHARED_LIBRARY)
