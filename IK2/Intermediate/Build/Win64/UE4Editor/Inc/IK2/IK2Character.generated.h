// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IK2_IK2Character_generated_h
#error "IK2Character.generated.h already included, missing '#pragma once' in IK2Character.h"
#endif
#define IK2_IK2Character_generated_h

#define IK2_Source_IK2_IK2Character_h_12_RPC_WRAPPERS
#define IK2_Source_IK2_IK2Character_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define IK2_Source_IK2_IK2Character_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAIK2Character(); \
	friend struct Z_Construct_UClass_AIK2Character_Statics; \
public: \
	DECLARE_CLASS(AIK2Character, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/IK2"), NO_API) \
	DECLARE_SERIALIZER(AIK2Character)


#define IK2_Source_IK2_IK2Character_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAIK2Character(); \
	friend struct Z_Construct_UClass_AIK2Character_Statics; \
public: \
	DECLARE_CLASS(AIK2Character, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/IK2"), NO_API) \
	DECLARE_SERIALIZER(AIK2Character)


#define IK2_Source_IK2_IK2Character_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AIK2Character(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AIK2Character) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AIK2Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AIK2Character); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AIK2Character(AIK2Character&&); \
	NO_API AIK2Character(const AIK2Character&); \
public:


#define IK2_Source_IK2_IK2Character_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AIK2Character(AIK2Character&&); \
	NO_API AIK2Character(const AIK2Character&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AIK2Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AIK2Character); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AIK2Character)


#define IK2_Source_IK2_IK2Character_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AIK2Character, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AIK2Character, FollowCamera); }


#define IK2_Source_IK2_IK2Character_h_9_PROLOG
#define IK2_Source_IK2_IK2Character_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IK2_Source_IK2_IK2Character_h_12_PRIVATE_PROPERTY_OFFSET \
	IK2_Source_IK2_IK2Character_h_12_RPC_WRAPPERS \
	IK2_Source_IK2_IK2Character_h_12_INCLASS \
	IK2_Source_IK2_IK2Character_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IK2_Source_IK2_IK2Character_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IK2_Source_IK2_IK2Character_h_12_PRIVATE_PROPERTY_OFFSET \
	IK2_Source_IK2_IK2Character_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	IK2_Source_IK2_IK2Character_h_12_INCLASS_NO_PURE_DECLS \
	IK2_Source_IK2_IK2Character_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IK2_API UClass* StaticClass<class AIK2Character>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IK2_Source_IK2_IK2Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
