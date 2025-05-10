KEY_CANCELLATION_ENABLE = yes
LTO_ENABLE = no
CONSOLE_ENABLE = no

# $(warning KEY_CANCELLATION_ENABLE is Enabled)
ifeq ($(KEY_CANCELLATION_ENABLE), yes)
  $(info KEY_CANCELLATION_ENABLE is Enabled)
endif

# $(warning LTO_ENABLE is Enabled)
ifeq ($(LTO_ENABLE), yes)
  $(info LTO_ENABLE is Enabled)
endif

# $(warning CONSOLE_ENABLE is Enabled)
ifeq ($(CONSOLE_ENABLE), yes)
  $(info CONSOLE_ENABLE is Enabled)
endif