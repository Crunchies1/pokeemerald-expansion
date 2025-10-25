### List of changes for development

Skip intro in order to speed up testing. Files changed:
- 

### Adding new abilities

Add the ability number in `include/constants/abilities.h`

Add the ability details in `src/data/abilities.h`
- Note that the name of the ability has to be <= 16 chars long.
- Note that the description also has to be less than a certain length.

For normal abilities, you'll likely be changing:
`src/battle_util.c`

For abilities which work during the damage calculation phase, you'll likely be changing:
`src/battle_script_commands.c`

If there are any special variables, you should modify files like:
`data/battle_scripts_1.s`
`include/battle_scripts.h`
`include/battle.h`

### Allowing non-regular abilities

To allow trainers to have custom abilities that aren't normally available to their species:

1. **Bypass trainer ability validation** in `src/battle_main.c`:
   - Modify `CreateNPCTrainerPartyFromTrainer` function (around lines 1953-1974)
   - Add special case for custom abilities to skip normal validation
   - Example: Check for `ABILITY_CHARMELEON_EVOLUTION` and bypass species ability checks

2. **Override abilities during battle initialization** in `src/battle_main.c`:
   - Add custom ability override after line 3485 in `BATTLE_INTRO_STATE_DRAW_SPRITES`
   - Create helper function `SetCustomTrainerAbilityIfNeeded()` to avoid code duplication
   - Add function declaration to `include/battle_main.h`

3. **Set custom abilities in trainers.party**:
   - Use direct ability reference: `Ability: ABILITY_CHARMELEON_EVOLUTION`
   - The `trainerproc` tool will convert this to the proper constant

### Implementing transformation abilities (like Charmeleon Evolution)

For abilities that transform Pokémon mid-battle:

1. **Add ability logic** in `src/battle_script_commands.c`:
   - In `Cmd_adjustdamage`: Prevent KO and set transformation flag
   - In `Cmd_resultmessage`: Handle the transformation sequence
   - Set `gBattleScripting.battler` before calling battle scripts

2. **Add DisableStruct flag** in `include/battle.h`:
   - Add bitfield like `u8 charmeleonEvolution:1;` to track transformation state

3. **Create battle script** in `data/battle_scripts_1.s`:
   - Handle animations, messages, healing, and optional move usage
   - Use `BS_SCRIPTING` for consistent battler reference
   - Example sequence: animation → transformation message → healing → optional move

4. **Add battle script declaration** in `include/battle_scripts.h`:
   - `extern const u8 BattleScript_CharmeleonEvolution[];`

5. **Handle nickname changes properly**:
   - Use `StringCopy_Nickname()` instead of `StringCopy()` for battle mon nicknames
   - Use `GetSpeciesName()` for proper species name formatting
   - Update both `gBattleMons[battler].nickname` and party mon nickname via `SetMonData()`

6. **Add battle message constants**:
   - Add `STRINGID_SRCPKMNREGAINEDHEALTH` to `include/constants/battle_string_ids.h`
   - Add corresponding message in `src/battle_message.c`
   - Use appropriate text placeholder (e.g., `{B_DEF_NAME_WITH_PREFIX}`)

7. **Add move result flag** in `include/constants/battle.h`:
   - `#define MOVE_RESULT_CHARMELEON_EVOLUTION (1 << X)` for tracking transformation

### Testing custom abilities

1. **Enable debug prints** (optional):
   - Comment out `#define NDEBUG` in `include/config/general.h`
   - Add `#include "gba/isagbprint.h"` to source files
   - Use `DebugPrintfLevel(MGBA_LOG_WARN, "message", args)` for debugging

2. **Create test files**:
   - Add test in `test/battle/ability/` directory
   - Use `SINGLE_BATTLE_TEST` macro with `GIVEN`/`WHEN`/`SCENE` structure
   - Test transformation, healing, and name changes

3. **Run tests**:
   - `make check TESTS="ability_name"` for specific ability tests
   - `make check` for all tests

### Common pitfalls

- **Ability name length**: Must be ≤ 16 characters (use `ABILITY_NAME_LENGTH`)
- **Battle script timing**: Set `gBattleScripting.battler` before calling battle scripts
- **Nickname formatting**: Use `StringCopy_Nickname()` and `GetSpeciesName()` for proper formatting
- **Message placeholders**: Use existing constants like `B_DEF_NAME_WITH_PREFIX` instead of creating new ones
- **Ability validation**: Custom abilities need special handling in both trainer creation and battle initialization