// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IK2_IK2GameMode_generated_h
#error "IK2GameMode.generated.h already included, missing '#pragma once' in IK2GameMode.h"
#endif
#define IK2_IK2GameMode_generated_h

#define IK2_Source_IK2_IK2GameMode_h_12_RPC_WRAPPERS
#define IK2_Source_IK2_IK2GameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define IK2_Source_IK2_IK2GameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAIK2GameMode(); \
	friend struct Z_Construct_UClass_AIK2GameMode_Statics; \
public: \
	DECLARE_CLASS(AIK2GameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/IK2"), IK2_API) \
	DECLARE_SERIALIZER(AIK2GameMode)


#define IK2_Source_IK2_IK2GameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAIK2GameMode(); \
	friend struct Z_Construct_UClass_AIK2GameMode_Statics; \
public: \
	DECLARE_CLASS(AIK2GameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/IK2"), IK2_API) \
	DECLARE_SERIALIZER(AIK2GameMode)


#define IK2_Source_IK2_IK2GameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	IK2_API AIK2GameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AIK2GameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(IK2_API, AIK2GameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AIK2GameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	IK2_API AIK2GameMode(AIK2GameMode&&); \
	IK2_API AIK2GameMode(const AIK2GameMode&); \
public:


#define IK2_Source_IK2_IK2GameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	IK2_API AIK2GameMode(AIK2GameMode&&); \
	IK2_API AIK2GameMode(const AIK2GameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(IK2_API, AIK2GameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AIK2GameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AIK2GameMode)


#define IK2_Source_IK2_IK2GameMode_h_12_PRIVATE_PROPERTY_OFFSET
#define IK2_Source_IK2_IK2GameMode_h_9_PROLOG
#define IK2_Source_IK2_IK2GameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IK2_Source_IK2_IK2GameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	IK2_Source_IK2_IK2GameMode_h_12_RPC_WRAPPERS \
	IK2_Source_IK2_IK2GameMode_h_12_INCLASS \
	IK2_Source_IK2_IK2GameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IK2_Source_IK2_IK2GameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IK2_Source_IK2_IK2GameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	IK2_Source_IK2_IK2GameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	IK2_Source_IK2_IK2GameMode_h_12_INCLASS_NO_PURE_DECLS \
	IK2_Source_IK2_IK2GameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IK2_API UClass* StaticClass<class AIK2GameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IK2_Source_IK2_IK2GameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
