def can_build(env, platform):
    return True


def configure(env):
    from SCons.Script import ARGUMENTS

    keyboardhook_enable = ARGUMENTS.get("keyboardhook_enable", "none")
    if keyboardhook_enable != "none":
        env["keyboardhook_enable"] = keyboardhook_enable


def is_enabled():
    return True
