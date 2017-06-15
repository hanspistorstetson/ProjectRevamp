class QrController < ApplicationController

  def new
    uuid = params[:qr][:uuid]
    @qrcode = RQRCode::QRCode.new(uuid, :size => 8, :level => :h)
  end

  def read
    value = %x(python --version 2>&1)
    puts value
    redirect_to current_user
  end

end
