<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	        version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

  <xsl:import href="/usr/share/xml/docbook/stylesheet/docbook-xsl/xhtml5/docbook.xsl"/>
  <xsl:output method="xml" indent="yes" encoding="US-ASCII"/>
  
  <xsl:variable name="toc.section.depth">3</xsl:variable>
  <xsl:variable name="toc.max.depth">3</xsl:variable>
  <xsl:variable name="toc.reference.toc">2</xsl:variable>
  <xsl:variable name="generate.section.toc.level">3</xsl:variable>

<xsl:param name="generate.toc">
 appendix  toc
 article   toc,title
 book      toc,title
 chapter   toc
 part      toc
 preface   toc
 qandadiv  toc
 qandaset  toc
 reference toc,title
 section1   toc
 section2   toc
 sect1   toc
 sect2   toc
 set       toc
 </xsl:param>

</xsl:stylesheet>
