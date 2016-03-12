#' Wirte and test my first R package
#'
#' A test function for R package development
#'
#' @param  input input variable
#' @param  target target variable
#' @importFrom plotly plot_ly
#'
#' @export

test_DArch <- function(input, target, ...) {
  darch <- darch(input, target, ...)
  plot_ly(z = getLayer(darch, 1)[[1]], type = "heatmap", colorscale = "hot")
  darch@stats$dataErrors$raw
  cat("Hello", ", world!")
  return(darch)
}


#' Print out a DArch object's weight
#'
#' Print function for DArch objects. The selected layer's weight is printed
#' in a heatmap
#'
#' @param darch an DArch instance
#' @param layer the number of the layer to print
#'
#' @importFrom plotly plot_ly
#'
#' @export

print_weight <- function(darch, layer) {
  weight <- getLayer(darch, layer)[[1]]
  plot_ly(z = weight, type = "heatmap", colorscale = "hot")
}



