//
//  PSPDFGlyph.h
//  PSPDFKit
//
//  Copyright 2012 Peter Steinberger. All rights reserved.
//

#import "PSPDFKitGlobal.h"

@class PSPDFFontInfo;

// Global helper to convert glyphs to rects.
extern NSArray *PSPDFRectsFromGlyphs(NSArray *glyphs, CGAffineTransform t, CGRect *boundingBox);

/// Represents a single character (glyph) on the pdf page.
/// Adobe also might reference to this as "Quad".
@interface PSPDFGlyph : NSObject

/// Frame of the glyph.
@property (nonatomic, assign) CGRect frame;

/// Character content (usually a single character)
@property (nonatomic, copy) NSString *content;

/// Used font info.
@property (nonatomic, strong) PSPDFFontInfo *font;

// Set if after this glyph a \n is there.
@property (nonatomic, assign) BOOL lineBreaker;

/// Index set on the Glyph.
@property (nonatomic, assign) int indexOnPage;

/// Compare with second glyph on the X position.
- (NSComparisonResult)compareByXPosition:(PSPDFGlyph *)glyph;

- (BOOL)isOnSameLineAs:(PSPDFGlyph *)glyph;

@property (nonatomic, assign, readonly) CGFloat fontHeight;

- (BOOL)isOnSameLineSegmentAs:(PSPDFGlyph *)glyph;

/// Used for caching during longPress event.
@property (nonatomic, assign) CGRect cachedViewRect;

@end
