/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSURL_H_
#define _NSURL_H_

#import <Foundation/NSObject.h>

@class NSURLHandle;
@class NSNumber;
@class NSData;
@class NSArray;
@class NSDictionary;
@class NSError;

// Keys that apply to file system URLs.
FOUNDATION_EXPORT NSString* const NSURLAddedToDirectoryDateKey;
FOUNDATION_EXPORT NSString* const NSURLAttributeModificationDateKey;
FOUNDATION_EXPORT NSString* const NSURLFileScheme;
FOUNDATION_EXPORT NSString* const NSURLContentAccessDateKey;
FOUNDATION_EXPORT NSString* const NSURLContentModificationDateKey;
FOUNDATION_EXPORT NSString* const NSURLCreationDateKey;
FOUNDATION_EXPORT NSString* const NSURLCustomIconKey;
FOUNDATION_EXPORT NSString* const NSURLDocumentIdentifierKey;
FOUNDATION_EXPORT NSString* const NSURLEffectiveIconKey;
FOUNDATION_EXPORT NSString* const NSURLFileResourceIdentifierKey;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeKey;
FOUNDATION_EXPORT NSString* const NSURLFileSecurityKey;
FOUNDATION_EXPORT NSString* const NSURLHasHiddenExtensionKey;
FOUNDATION_EXPORT NSString* const NSURLIsDirectoryKey;
FOUNDATION_EXPORT NSString* const NSURLIsExcludedFromBackupKey;
FOUNDATION_EXPORT NSString* const NSURLIsExecutableKey;
FOUNDATION_EXPORT NSString* const NSURLIsHiddenKey;
FOUNDATION_EXPORT NSString* const NSURLIsMountTriggerKey;
FOUNDATION_EXPORT NSString* const NSURLIsPackageKey;
FOUNDATION_EXPORT NSString* const NSURLIsReadableKey;
FOUNDATION_EXPORT NSString* const NSURLIsRegularFileKey;
FOUNDATION_EXPORT NSString* const NSURLIsSymbolicLinkKey;
FOUNDATION_EXPORT NSString* const NSURLIsSystemImmutableKey;
FOUNDATION_EXPORT NSString* const NSURLIsUserImmutableKey;
FOUNDATION_EXPORT NSString* const NSURLIsVolumeKey;
FOUNDATION_EXPORT NSString* const NSURLIsWritableKey;
FOUNDATION_EXPORT NSString* const NSURLLabelColorKey;
FOUNDATION_EXPORT NSString* const NSURLLabelNumberKey;
FOUNDATION_EXPORT NSString* const NSURLLinkCountKey;
FOUNDATION_EXPORT NSString* const NSURLLocalizedLabelKey;
FOUNDATION_EXPORT NSString* const NSURLLocalizedNameKey;
FOUNDATION_EXPORT NSString* const NSURLLocalizedTypeDescriptionKey;
FOUNDATION_EXPORT NSString* const NSURLNameKey;
FOUNDATION_EXPORT NSString* const NSURLParentDirectoryURLKey;
FOUNDATION_EXPORT NSString* const NSURLPathKey;
FOUNDATION_EXPORT NSString* const NSURLPreferredIOBlockSizeKey;
FOUNDATION_EXPORT NSString* const NSURLTypeIdentifierKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIdentifierKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeURLKey;

// Possible values for the NSURLFileResourceTypeKey key.
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeNamedPipe;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeCharacterSpecial;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeDirectory;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeBlockSpecial;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeRegular;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeSymbolicLink;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeSocket;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeUnknown;

// Keys that apply to properties of files.
FOUNDATION_EXPORT NSString* const NSURLFileSizeKey;
FOUNDATION_EXPORT NSString* const NSURLFileAllocatedSizeKey;
FOUNDATION_EXPORT NSString* const NSURLIsAliasFileKey;
FOUNDATION_EXPORT NSString* const NSURLTotalFileAllocatedSizeKey;
FOUNDATION_EXPORT NSString* const NSURLTotalFileSizeKey;

struct EbrURL;

FOUNDATION_EXPORT_CLASS
@interface NSURL : NSObject <NSCopying, NSCoding>

- initWithScheme:(NSString*)scheme host:(NSString*)host path:(NSString*)path;
- (instancetype)initFileURLWithPath:(NSString*)path;
- initWithString:(NSString*)string;
- initWithString:(NSString*)string relativeToURL:(NSURL*)parent;

+ fileURLWithPath:(NSString*)path;
+ URLWithString:(NSString*)string;
+ URLWithString:(NSString*)string relativeToURL:(NSURL*)parent;
+ (id)fileURLWithPath:(NSString*)path isDirectory:(BOOL)isDir;

@property (readonly, copy) NSString* absoluteString;
@property (readonly, copy) NSString* parameterString;

- (id)propertyForKey:(NSString*)propertyKey;

@property (readonly, copy) NSString* scheme;
@property (readonly, copy) NSString* host;
@property (readonly, copy) NSString* user;
@property (readonly, copy) NSString* password;
@property (readonly, copy) NSString* fragment;
@property (readonly, copy) NSString* path;

@property (readonly, copy) NSNumber* port;
@property (readonly, copy) NSString* query;
@property (readonly, copy) NSString* relativePath;
@property (readonly, copy) NSString* relativeString;
@property (readonly, copy) NSString* resourceSpecifier;

- (BOOL)isFileReferenceURL;

@property (readonly, getter=isFileURL) BOOL fileURL;
@property (readonly, copy) NSURL* standardizedURL;
@property (readonly, copy) NSURL* absoluteURL;
@property (readonly, copy) NSURL* baseURL;

- (BOOL)setProperty:(id)propertyValue forKey:(NSString*)propertyKey;

- (BOOL)setResourceData:(NSData*)data;

- (NSData*)resourceDataUsingCache:(BOOL)useCache;
- (NSURLHandle*)URLHandleUsingCache:(BOOL)useCache;
- (void)loadResourceDataNotifyingClient:client usingCache:(BOOL)useCache;

- (NSURL*)URLByAppendingPathComponent:(NSString*)pathComponent isDirectory:(BOOL)isDirectory;
- (NSURL*)URLByAppendingPathComponent:(NSString*)pathComponent;
- (NSURL*)URLByAppendingPathExtension:(NSString*)pathExtension;
- (NSURL*)URLByDeletingLastPathComponent;

- (BOOL)checkResourceIsReachableAndReturnError:(NSError**)error;
- (NSString*)lastPathComponent;
- (NSString*)pathExtension;
- (BOOL)setResourceValue:(id)value forKey:(NSString*)key error:(NSError**)error;
- (BOOL)getResourceValue:(id*)value forKey:(NSString*)key error:(NSError**)error;
- (NSArray*)pathComponents;

- (NSDictionary*)resourceValuesForKeys:(NSArray*)keys error:(NSError**)error;

- (id)initFileURLWithPath:(NSString*)path isDirectory:(BOOL)isDir;

@end

#endif /* _NSURL_H_ */