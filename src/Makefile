SYS			:=	$(shell gcc -dumpmachine)
CC			=	g++

TARGET		=	test
SOURCES	= MThread.cpp main.cpp \

######################################## include
INCLUDE	+=	-I./

######################################## default
LDFLAGS += -lrt -lpthread

CPPFLAGS += -g -D_REENTRANT
CPPFLAGS += -O2 -std=c++11 -Wall -Wextra -Wfloat-equal -m64

# 용량 줄이기 옵션.
#-s             # 심볼 테이블 제거
#-fdata-sections # 사용하지 않는 데이터 섹션 제거 가능하게
#-ffunction-sections # 사용하지 않는 함수 섹션 제거 가능하게
#-Wl,--gc-sections # 링커에게 사용하지 않는 섹션 제거 지시
#CPPFLAGS += -Wl,--gc-sections -ffunction-sections -fdata-sections -s 

OBJECTS	:=	$(SOURCES:.cpp=.o)
DEPENDS	:=	$(SOURCES:.cpp=.d)

all: $(OBJECTS)
	rm -rf core.*
	$(CC) -o $(TARGET) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJECTS)

install: all
	rm -rf $(INSTALL_DIR)/$(TARGET).bak
	mv $(INSTALL_DIR)/$(TARGET) $(INSTALL_DIR)/$(TARGET).bak
	cp $(TARGET) $(INSTALL_DIR)

.c.o: $(.cpp.o)
.cpp.o:
	$(CC) $(INCLUDE) $(CPPFLAGS) -c $< -o $@
	
%d:%cpp
	$(CC) $(INCLUDE) $(CPPFLAGS) -MM -MP -MT "$(@:.d=.o) $@" -MF $@ $<

.PHONY: all

-include $(DEPENDS)
