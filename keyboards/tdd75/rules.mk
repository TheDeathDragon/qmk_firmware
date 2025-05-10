KEY_CANCELLATION_ENABLE = yes
E_MACRO_ENABLE = yes
LTO_ENABLE = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = yes

# $(warning KEY_CANCELLATION_ENABLE is Enabled)
ifeq ($(KEY_CANCELLATION_ENABLE), yes)
  $(info KEY_CANCELLATION_ENABLE is Enabled)
endif

# $(warning E_MACRO_ENABLE is Enabled)
ifeq ($(E_MACRO_ENABLE), yes)
  $(info E_MACRO_ENABLE is Enabled)
endif

# $(warning LTO_ENABLE is Enabled)
ifeq ($(LTO_ENABLE), yes)
  $(info LTO_ENABLE is Enabled)
endif

# $(warning CONSOLE_ENABLE is Enabled)
ifeq ($(CONSOLE_ENABLE), yes)
  $(info CONSOLE_ENABLE is Enabled)
endif

# $(warning MOUSEKEY_ENABLE is Enabled)
ifeq ($(MOUSEKEY_ENABLE), yes)
  $(info MOUSEKEY_ENABLE is Enabled)
endif
